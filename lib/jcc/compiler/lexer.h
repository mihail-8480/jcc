#pragma once
#include "../string.h"
#include "../flag.h"

typedef enum jcc_token_type
{
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_SPECIAL,
    TOKEN_INTEGER_LITERAL,
    TOKEN_FLOAT_LITERAL,
    TOKEN_STRING_LITERAL
} jcc_token_type_t;

typedef enum jcc_token_literal_modifier
{
    FLAG(TOKEN_MOD_DEFAULT, 0),
    FLAG(TOKEN_MOD_HEX, 2),
    FLAG(TOKEN_MOD_OCTAL, 3),
    FLAG(TOKEN_MOD_BINARY, 4),
    FLAG(TOKEN_MOD_CHAR, 5),
    FLAG(TOKEN_MOD_EXPONENT, 6),
    FLAG(TOKEN_MOD_SUFFIX, 7)
} jcc_token_literal_modifier_t;

typedef struct jcc_token
{
    jcc_string_t value;
    jcc_token_type_t type;
    jcc_token_literal_modifier_t literal_mod;
} jcc_token_t;

typedef struct jcc_unit
{
    jcc_cstr_ptr content;
    jcc_size_t position;
    jcc_cstr_ptr path;
} jcc_unit_t;

#define __T__ jcc_token_t
typedef OPTIONAL jcc_optional_token_t;
typedef jcc_optional_token_t jcc_token_parser_t(jcc_unit_t *unit);

typedef struct jcc_lexer_context
{
    jcc_unit_t unit;
    jcc_size_t token_parsers_length;
    jcc_token_parser_t **token_parsers;
} jcc_lexer_context_t;

jcc_optional_token_t jcc_token_next(jcc_lexer_context_t *context);

#undef __T__
