#include <jcc/string.h>
#include <jcc/platform.h>
#include INTERFACE(STRING)

#define __T__ jcc_string_t
jcc_optional_string_t jcc_substring(const jcc_string_t *base, jcc_size_t offset, jcc_size_t length)
{
    NONE_IF_NULL(base);
    NONE_IF_NULL(base->value);
    if (offset + length > base->length)
    {
        return NONE;
    }

    return SOME((jcc_string_t){
        .length = length,
        .value = base->value + offset,
    });
}
#undef __T__

#define __T__ jcc_string_t
jcc_optional_string_t jcc_string_from_cstr(jcc_cstr_ptr cstr)
{
    NONE_IF_NULL(cstr);
    return SOME((jcc_string_t){
        .value = cstr,
        .length = CALL(STRING, STRLEN, cstr),
    });
}
#undef __T__
