#include <jcc/compiler/compiler.h>
#include "defs.h"

#define __T__ jcc_file_context_t

jcc_token_parser_t *token_parsers[] = {
    jcc_token_parse_keyword,
    jcc_token_parse_identifier,
    jcc_token_parse_operator,
    jcc_token_parse_special,
    jcc_token_parse_integer_literal,
    jcc_token_parse_float_literal,
    jcc_token_parse_string_literal,
};

jcc_optional_file_context_t jcc_get_file_context([[maybe_unused]] jcc_cstr_ptr file)
{
    FIXME("File loading is not implemented");

    return SOME((jcc_file_context_t){
        .lexer = {
            .token_parsers = token_parsers,
            .token_parsers_length = sizeof(token_parsers) / sizeof(token_parsers[0]),
            .unit = {
                .content = "",
                .position = 0,
                .path = file,
            },
        },
    });
}

#undef __T__
