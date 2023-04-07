#include <jcc/string.h>
#include <jcc/attributes.h>

JCC_OPTIONAL_TYPE(jcc_string_t)
jcc_substring(const jcc_string_t *base, jcc_size_t offset, jcc_size_t length)
{
    if (offset + length > base->length)
    {
        return JCC_NONE(jcc_string_t);
    }

    return JCC_SOME(jcc_string_t, {.length = length, .value = base->value + offset});
}
