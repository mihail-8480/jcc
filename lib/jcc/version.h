#pragma once
#include "macros.h"

#define VERSION_NUM EXPAND_AND_STRINGIFY(VERSION_MAJOR) "." EXPAND_AND_STRINGIFY(VERSION_MINOR) "." EXPAND_AND_STRINGIFY(VERSION_PATCH)

#ifdef DEBUG
#define VERSION_SUFFIX "-debug"
#else
#define VERSION_SUFFIX ""
#endif

#ifndef IMPL
#define IMPL
#include "platform.h"
#undef IMPL
#else
#include "platform.h"
#endif

#undef PLATFORM_DEFAULT
#undef INTERFACE
#undef CALL
#undef CONST
#ifdef PLATFORM_DEFAULTED
#define VERSION_PLATFORM() EXPAND_AND_STRINGIFY(PLATFORM) "-default"
#undef PLATFORM_DEFAULTED
#else
#define VERSION_PLATFORM() EXPAND_AND_STRINGIFY(PLATFORM)
#endif

#ifndef GIT_HASH
#define GIT_HASH "<unknown>"
#endif

#ifndef GIT_BRANCH
#define GIT_BRANCH "<unknown>"
#endif

#ifndef GIT_REMOTE
#define GIT_REMOTE "<unknown>"
#endif

#ifdef GIT_CLEAN
#define VERSION "v" VERSION_NUM VERSION_SUFFIX
#define VERSION_FULL VERSION " (git: " GIT_BRANCH "/" GIT_HASH ", source: " GIT_REMOTE ", platform: " VERSION_PLATFORM() ")"
#else
#define VERSION "dev"
#define VERSION_FULL "dev (git: " GIT_BRANCH "/" GIT_HASH ", source: " GIT_REMOTE ", platform: " VERSION_PLATFORM() ")"
#endif

void jcc_register_component(const char *name, const char *version);