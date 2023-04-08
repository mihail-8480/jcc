#include <jcc/version.h>
#include <jcc/string.h>

#define __T__ jcc_cstr_ptr
OPTIONAL nonnul_string(jcc_cstr_ptr str)
{
    if (!str)
    {
        return NONE;
    }
    return SOME(str);
}
#undef __T__

#define __T__ bool
OPTIONAL opt_strlen(jcc_cstr_ptr str)
{
    AUTO valid_str = TRY(nonnul_string(str));
    AUTO len = 0;

    while (valid_str[len])
        len++;

    return SOME(len);
}
#undef __T__

int main()
{
    LOG("Version: " VERSION);
    UNWRAP(opt_strlen("test"));
    UNWRAP(opt_strlen(0));

    return 0;
}
