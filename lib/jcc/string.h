#pragma once
#include "numeric.h"
#include "optional.h"

typedef const jcc_byte_t *jcc_cstr_ptr;

typedef struct jcc_string
{
    jcc_size_t length;
    jcc_cstr_ptr value;
} jcc_string_t;

#define __T__ jcc_string_t
typedef OPTIONAL jcc_optional_string_t;
#undef __T__

#define CONST_STRING(__literal__) ((jcc_string_t){.length = sizeof(__literal__) - 1, .value = (__literal__)})
#define CONST_ARRAY_STRING(__literal__) ((jcc_string_t){.length = sizeof(__literal__), .value = (__literal__)})

jcc_optional_string_t jcc_string_from_cstr(jcc_cstr_ptr cstr);
jcc_optional_string_t jcc_substring(const jcc_string_t *base, jcc_size_t offset, jcc_size_t length);
