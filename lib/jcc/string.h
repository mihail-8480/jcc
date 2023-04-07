#pragma once
#include "numeric.h"
#include "optional.h"
#include "attributes.h"

typedef char jcc_byte_t;

typedef jcc_byte_t *jcc_cstr_ptr;

typedef struct jcc_string
{
    jcc_size_t length;
    jcc_cstr_ptr value;
} jcc_string_t;

JCC_OPTIONAL(jcc_string_t)
jcc_substring(const jcc_string_t *base, jcc_size_t offset, jcc_size_t length);