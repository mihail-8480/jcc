#include <jcc/string.h>
#include <jcc/platform.h>
#include JCC_INTERFACE(string)

#define __T__ jcc_string_t
jcc_optional_string_t
jcc_substring(const jcc_string_t *base, jcc_size_t offset, jcc_size_t length)
{
    JCC_NONE_IF_NULL(base);
    JCC_NONE_IF_NULL(base->value);
    if (offset + length > base->length)
    {
        return JCC_NONE;
    }

    return JCC_SOME((jcc_string_t){.length = length, .value = base->value + offset});
}
#undef __T__

#define __T__ jcc_string_t
jcc_optional_string_t jcc_string_from_cstr(jcc_cstr_ptr cstr)
{
    JCC_NONE_IF_NULL(cstr);
    return JCC_SOME((jcc_string_t){.value = cstr,
                                   .length = JCC_CALL(STRING, STRLEN, cstr)});
}
#undef __T__
