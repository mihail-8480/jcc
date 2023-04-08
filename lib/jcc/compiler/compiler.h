#pragma once
#include "lexer.h"

typedef struct jcc_file_context
{
    jcc_lexer_context_t lexer;
} jcc_file_context_t;

#define __T__ jcc_file_context_t
typedef OPTIONAL jcc_optional_file_context_t;
#undef __T__

jcc_optional_file_context_t jcc_get_file_context(jcc_cstr_ptr file);
