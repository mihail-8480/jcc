#include <jcc/version.h>
#include <jcc/string.h>

#define __T__ void
OPTIONAL_VOID test()
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
