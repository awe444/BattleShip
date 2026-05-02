/**
 * Android JNI for virtual gamepad + camera state.
 * Lives under port/ (BattleShip-owned) so libultraship stays an unmodified submodule.
 */
#ifdef __ANDROID__

#include <SDL_gamecontroller.h>
#include <SDL2/SDL.h>
#include <jni.h>

namespace {

static float cameraYaw;
static float cameraPitch;

static int virtual_joystick_id = -1;
static SDL_Joystick* virtual_joystick = nullptr;

} // namespace

extern "C" void JNICALL Java_com_battleship_android_MainActivity_attachController(JNIEnv* env, jobject obj) {
    virtual_joystick_id = SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_GAMECONTROLLER, 6, 18, 0);
    if (virtual_joystick_id == -1) {
        SDL_Log("Could not create overlay virtual controller");
        return;
    }

    virtual_joystick = SDL_JoystickOpen(virtual_joystick_id);
    if (virtual_joystick == nullptr) {
        SDL_Log("Could not create virtual joystick");
    }
}

extern "C" void JNICALL Java_com_battleship_android_MainActivity_setCameraState(JNIEnv* env, jobject jobj, jint axis,
                                                                                jfloat value) {
    switch (axis) {
        case 0:
            cameraYaw = value;
            break;
        case 1:
            cameraPitch = value;
            break;
    }
}

extern "C" void JNICALL Java_com_battleship_android_MainActivity_setButton(JNIEnv* env, jobject jobj, jint button,
                                                                           jboolean value) {
    if (button < 0) {
        SDL_JoystickSetVirtualAxis(virtual_joystick, -button, value ? SDL_MAX_SINT16 : -SDL_MAX_SINT16);
    } else {
        SDL_JoystickSetVirtualButton(virtual_joystick, button, value);
    }
}

extern "C" void JNICALL Java_com_battleship_android_MainActivity_setAxis(JNIEnv* env, jobject jobj, jint axis,
                                                                         jshort value) {
    SDL_JoystickSetVirtualAxis(virtual_joystick, axis, value);
}

extern "C" void JNICALL Java_com_battleship_android_MainActivity_detachController(JNIEnv* env, jobject jobj) {
    SDL_JoystickClose(virtual_joystick);
    SDL_JoystickDetachVirtual(virtual_joystick_id);
    virtual_joystick = nullptr;
    virtual_joystick_id = -1;
}

extern "C" JNIEXPORT void JNICALL Java_com_battleship_android_MainActivity_nativeHandleSelectedFile(JNIEnv* env,
                                                                                                    jobject thiz,
                                                                                                    jstring filename) {
}

#endif // __ANDROID__
