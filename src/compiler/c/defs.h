#pragma once
#include <jcc/compiler/lexer.h>

jcc_optional_token_t jcc_token_parse_keyword(jcc_unit_t *unit);
jcc_optional_token_t jcc_token_parse_identifier(jcc_unit_t *unit);
jcc_optional_token_t jcc_token_parse_operator(jcc_unit_t *unit);
jcc_optional_token_t jcc_token_parse_special(jcc_unit_t *unit);
jcc_optional_token_t jcc_token_parse_integer_literal(jcc_unit_t *unit);
jcc_optional_token_t jcc_token_parse_float_literal(jcc_unit_t *unit);
jcc_optional_token_t jcc_token_parse_string_literal(jcc_unit_t *unit);
