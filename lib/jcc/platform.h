#ifndef INTERFACE

#ifndef IMPL
#error Cannot include <jcc/platform.h> outside of libcore.
#endif

#define PLATFORM_DEFAULT libc
#ifndef PLATFORM
#define PLATFORM PLATFORM_DEFAULT
#define PLATFORM_DEFAULTED
#endif

#define INTERFACE(__interface__) <jcc/platform/PLATFORM/__interface__.interface.h>
#define CALL(__interface__, __function__, ...) INTERFACE_##__interface__##_##__function__(__VA_ARGS__)
#define CONST(__interface__, __name__) INTERFACE_##__interface__##_##__name__
#endif