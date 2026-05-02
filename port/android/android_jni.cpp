/**
 * Android JNI entry points previously used for the on-screen virtual gamepad.
 * Touch overlay was removed; physical controllers are handled entirely by SDL.
 */
#ifdef __ANDROID__

// Intentionally empty — keep this translation unit so the Android CMake target
// continues to list a stable jni source path.

#endif // __ANDROID__
