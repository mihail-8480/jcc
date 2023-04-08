#pragma once

#include <string.h>
#include <stdio.h>

#define INTERFACE_STRING_STRLEN(__cstr__) strlen(__cstr__)
#define INTERFACE_STRING_FORMAT(__buffer__, ...) sprintf(__buffer__, __VA_ARGS__)