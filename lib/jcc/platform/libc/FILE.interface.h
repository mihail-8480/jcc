#pragma once

#include <stdio.h>
#include <unistd.h>

#define INTERFACE_FILE_FORMAT_PRINT(__stream__, ...) fprintf(__stream__, __VA_ARGS__)
#define INTERFACE_FILE_GET_NATIVE_STREAM_FROM_FD(__fd__, __mode__) fdopen(dup(__fd__), __mode__)
#define INTERFACE_FILE_CLOSE_NATIVE_STREAM(__stream__) fclose(__stream__)

typedef enum jcc_standard_fds
{
    INTERFACE_FILE_FD_IN = 0,
    INTERFACE_FILE_FD_OUT = 1,
    INTERFACE_FILE_FD_ERR = 2
} jcc_standard_fds_t;