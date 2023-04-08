#pragma once

#ifndef JCC_IMPL
#error Cannot include <jcc/platform.h> outside of non-jcc executables.
#endif

#define JCC_PLATFORM_DEFAULT libc
#ifndef JCC_PLATFORM
#define JCC_PLATFORM JCC_PLATFORM_DEFAULT
#endif

#define JCC_INTERFACE(__interface__) <jcc/platform/JCC_PLATFORM/__interface__.interface.h>
