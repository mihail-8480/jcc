#pragma once
#include "macros.h"

#define JCC_VERSION_NUM JCC_EXPAND_AND_STRINGIFY(JCC_VERSION_MAJOR) "." JCC_EXPAND_AND_STRINGIFY(JCC_VERSION_MINOR) "." JCC_EXPAND_AND_STRINGIFY(JCC_VERSION_PATCH)

#ifdef JCC_DEBUG
#define JCC_VERSION_SUFFIX "-debug"
#else
#define JCC_VERSION_SUFFIX ""
#endif

#define JCC_IMPL
#include "platform.h"
#undef JCC_IMPL
#undef JCC_PLATFORM_DEFAULT
#undef JCC_INTERFACE
#undef JCC_CALL
#undef JCC_CONST
#ifdef JCC_PLATFORM_DEFAULTED
#define JCC_VERSION_PLATFORM() JCC_EXPAND_AND_STRINGIFY(JCC_PLATFORM) "-default"
#undef JCC_PLATFORM_DEFAULTED
#else
#define JCC_VERSION_PLATFORM() JCC_EXPAND_AND_STRINGIFY(JCC_PLATFORM)
#endif

#define JCC_VERSION "v" JCC_VERSION_NUM JCC_VERSION_SUFFIX " (commit: " JCC_GIT_HASH ", platform: " JCC_VERSION_PLATFORM() ")"