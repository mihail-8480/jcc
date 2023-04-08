#include <jcc/version.h>
#include <jcc/string.h>
#include <jcc/flag.h>

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
} jcc_unit_t;

#define __T__ jcc_token_t
typedef OPTIONAL jcc_optional_token_t;
typedef jcc_optional_token_t jcc_token_parser_t(jcc_unit_t *unit);

jcc_optional_token_t jcc_token_parse_keyword([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

jcc_optional_token_t jcc_token_parse_identifier([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

jcc_optional_token_t jcc_token_parse_operator([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

jcc_optional_token_t jcc_token_parse_special([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

jcc_optional_token_t jcc_token_parse_integer_literal([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

jcc_optional_token_t jcc_token_parse_float_literal([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

jcc_optional_token_t jcc_token_parse_string_literal([[maybe_unused]] jcc_unit_t *unit)
{
    LOG_ERR("Not implemented");
    return NONE;
}

typedef struct jcc_lexer_context
{
    jcc_unit_t *unit;
    jcc_size_t token_parsers_length;
    jcc_token_parser_t *token_parsers[];
} jcc_lexer_context_t;

jcc_optional_token_t jcc_token_next(jcc_lexer_context_t *context)
{
    NONE_IF_NULL(context);
    NONE_IF_NULL(context->token_parsers);
    NONE_IF_NULL(context->unit);
    NONE_IF_NULL(context->unit->content);

    for (AUTO i = 0; context->token_parsers_length; i++)
    {
        AUTO result = context->token_parsers[i](context->unit);
        if (result.has_value)
        {
            return result;
        }
    }
    return NONE;
}
#undef __T__

typedef struct jcc_file_context
{
    jcc_lexer_context_t lexer;
} jcc_file_context_t;

#define __T__ jcc_file_context_t
typedef OPTIONAL jcc_optional_file_context_t;

jcc_optional_file_context_t jcc_get_file_context([[maybe_unused]] jcc_cstr_ptr file, [[maybe_unused]] jcc_cstr_ptr language)
{
    return NONE;
}

#undef __T__


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    AUTO context = UNWRAP(jcc_get_file_context("src/main.c", ""));
    jcc_optional_token_t token;
    do
    {
        token = jcc_token_next(&context.lexer);
        
    } while (token.has_value);
}
