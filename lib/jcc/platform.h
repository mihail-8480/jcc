#ifndef JCC_INTERFACE

#ifndef JCC_IMPL
#error Cannot include <jcc/platform.h> outside of libcore.
#endif

#define JCC_PLATFORM_DEFAULT libc
#ifndef JCC_PLATFORM
#define JCC_PLATFORM JCC_PLATFORM_DEFAULT
#define JCC_PLATFORM_DEFAULTED
#endif

#define JCC_INTERFACE(__interface__) <jcc/platform/JCC_PLATFORM/__interface__.interface.h>
#endif