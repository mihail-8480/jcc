#include <jcc/version.h>
#include <jcc/string.h>

#define __T__ void
JCC_VOID_OPTIONAL test() {
    return JCC_NONE;
}
#undef __T__

int main()
{
    jcc_log_info(JCC_VERSION);
    JCC_UNWRAP(test());
    return 0;
}
