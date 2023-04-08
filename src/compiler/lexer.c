#include <jcc/compiler/lexer.h>
#define __T__ jcc_token_t

jcc_optional_token_t jcc_token_next(jcc_lexer_context_t *context)
{
    NONE_IF_NULL(context);
    NONE_IF_NULL(context->token_parsers);
    NONE_IF_NULL(context->unit.content);

    for (jcc_size_t i = 0; i < context->token_parsers_length; i++)
    {
        AUTO result = context->token_parsers[i](&context->unit);
        if (result.has_value)
        {
            return result;
        }
    }
    return NONE;
}
#undef __T__
