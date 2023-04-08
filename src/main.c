#include <jcc/version.h>
#include <jcc/string.h>

#define __T__ void
VOID_OPTIONAL test()
{
    return NONE;
}
#undef __T__

int main()
{
    LOG("Version: " VERSION);
    UNWRAP(test());
    return 0;
}
