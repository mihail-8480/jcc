#pragma once

#include "numeric.h"

typedef struct jcc_code_location
{
    const jcc_byte_t *file_name;
    jcc_uint_t file_line;
    const jcc_byte_t *function_name;
    jcc_size_t function_address;
} jcc_code_location_t;

#ifndef SOURCE_PATH_SIZE
#define SOURCE_PATH_SIZE 0
#endif

#define __FILENAME__ (__FILE__ + SOURCE_PATH_SIZE)
#define CODE_LOCATION(x) ((jcc_code_location_t){.file_name = __FILENAME__, .file_line = __LINE__, .function_name = #x, .function_address = (jcc_size_t)x})
#define CODE_LOCATION_ANY() ((jcc_code_location_t){.file_name = __FILENAME__, .file_line = __LINE__, .function_name = __func__, .function_address = (jcc_size_t)0})
