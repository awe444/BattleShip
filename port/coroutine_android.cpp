/**
 * coroutine_android.cpp — pthread + condvar coroutines for Android.
 *
 * Bionic omits legacy ucontext (getcontext/swapcontext/makecontext). Each
 * logical coroutine runs on a dedicated pthread; resume/yield use a parked /
 * want_run handshake matching "run until yield or entry return".
 */

#if defined(__ANDROID__) || defined(ANDROID)

#include "coroutine.h"
#include "port_watchdog.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_STACK_SIZE (64 * 1024)

struct PortCoroutine {
	pthread_mutex_t mu;
	pthread_cond_t cv_child;
	pthread_cond_t cv_parent;
	pthread_t thread;
	int want_run;
	int parked;
	int finished;
	int shutdown;
	int thread_started;
	void (*entry)(void *);
	void *arg;
	size_t stack_size;
};

static __thread PortCoroutine *sCurrentCoroutine = NULL;

static void *co_thread_main(void *p)
{
	PortCoroutine *co = (PortCoroutine *)p;

	pthread_mutex_lock(&co->mu);
	while (!co->shutdown) {
		while (!co->want_run && !co->shutdown) {
			pthread_cond_wait(&co->cv_child, &co->mu);
		}
		if (co->shutdown) {
			break;
		}
		co->want_run = 0;
		co->parked = 0;
		pthread_cond_signal(&co->cv_parent);
		pthread_mutex_unlock(&co->mu);

		sCurrentCoroutine = co;
		co->entry(co->arg);
		sCurrentCoroutine = NULL;

		pthread_mutex_lock(&co->mu);
		co->parked = 1;
		co->finished = 1;
		pthread_cond_signal(&co->cv_parent);
		/* entry() runs once per coroutine lifetime (yields are inside it). */
		while (!co->shutdown) {
			pthread_cond_wait(&co->cv_child, &co->mu);
		}
	}
	pthread_mutex_unlock(&co->mu);
	return NULL;
}

void port_coroutine_init_main(void)
{
}

PortCoroutine *port_coroutine_create(void (*entry)(void *), void *arg,
				     size_t stack_size)
{
	if (stack_size < MIN_STACK_SIZE) {
		stack_size = MIN_STACK_SIZE;
	}

	PortCoroutine *co = (PortCoroutine *)calloc(1, sizeof(PortCoroutine));
	if (co == NULL) {
		return NULL;
	}

	co->entry = entry;
	co->arg = arg;
	co->stack_size = stack_size;
	co->parked = 0;

	if (pthread_mutex_init(&co->mu, NULL) != 0) {
		free(co);
		return NULL;
	}
	if (pthread_cond_init(&co->cv_child, NULL) != 0 ||
	    pthread_cond_init(&co->cv_parent, NULL) != 0) {
		pthread_mutex_destroy(&co->mu);
		free(co);
		return NULL;
	}

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	size_t ss = stack_size;
	if (ss < (size_t)PTHREAD_STACK_MIN) {
		ss = (size_t)PTHREAD_STACK_MIN;
	}
	pthread_attr_setstacksize(&attr, ss);

	if (pthread_create(&co->thread, &attr, co_thread_main, co) != 0) {
		pthread_attr_destroy(&attr);
		pthread_cond_destroy(&co->cv_parent);
		pthread_cond_destroy(&co->cv_child);
		pthread_mutex_destroy(&co->mu);
		free(co);
		return NULL;
	}
	pthread_attr_destroy(&attr);
	co->thread_started = 1;
	return co;
}

void port_coroutine_destroy(PortCoroutine *co)
{
	if (co == NULL) {
		return;
	}

	if (co->thread_started) {
		pthread_mutex_lock(&co->mu);
		co->shutdown = 1;
		co->want_run = 1;
		pthread_cond_signal(&co->cv_child);
		pthread_mutex_unlock(&co->mu);
		pthread_join(co->thread, NULL);
	}

	pthread_cond_destroy(&co->cv_parent);
	pthread_cond_destroy(&co->cv_child);
	pthread_mutex_destroy(&co->mu);
	free(co);
}

void port_coroutine_resume(PortCoroutine *co)
{
	if (co == NULL) {
		return;
	}

	pthread_mutex_lock(&co->mu);
	if (co->finished) {
		pthread_mutex_unlock(&co->mu);
		return;
	}
	co->want_run = 1;
	pthread_cond_signal(&co->cv_child);
	while (!co->parked) {
		pthread_cond_wait(&co->cv_parent, &co->mu);
	}
	pthread_mutex_unlock(&co->mu);
}

void port_coroutine_yield(void)
{
	PortCoroutine *co = sCurrentCoroutine;
	if (co == NULL) {
		fprintf(stderr,
			"SSB64: port_coroutine_yield called outside coroutine\n");
		return;
	}

	port_watchdog_note_yield();

	pthread_mutex_lock(&co->mu);
	co->parked = 1;
	pthread_cond_signal(&co->cv_parent);
	while (!co->want_run && !co->shutdown) {
		pthread_cond_wait(&co->cv_child, &co->mu);
	}
	if (co->shutdown) {
		pthread_mutex_unlock(&co->mu);
		return;
	}
	co->want_run = 0;
	co->parked = 0;
	pthread_cond_signal(&co->cv_parent);
	pthread_mutex_unlock(&co->mu);
}

int port_coroutine_is_finished(PortCoroutine *co)
{
	if (co == NULL) {
		return 1;
	}
	return co->finished;
}

int port_coroutine_in_coroutine(void)
{
	return sCurrentCoroutine != NULL;
}

#endif /* __ANDROID__ || ANDROID */
