# Build libusb for Android before libultraship pulls hidapi.
# hidapi's libusb backend links to TARGET usb-1.0 if it exists; otherwise it
# uses pkg-config and -lusb-1.0, which is not available in the NDK sysroot.

include(FetchContent)

set(LIBUSB_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(LIBUSB_INSTALL_TARGETS OFF CACHE BOOL "" FORCE)
set(LIBUSB_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(LIBUSB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    libusb_cmake
    GIT_REPOSITORY https://github.com/libusb/libusb-cmake.git
    GIT_TAG v1.0.29-0
)
FetchContent_MakeAvailable(libusb_cmake)

if(NOT TARGET usb-1.0)
    message(FATAL_ERROR "Android libusb: expected target usb-1.0 from libusb-cmake")
endif()
