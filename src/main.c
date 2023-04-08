#include <jcc/version.h>
#include <jcc/string.h>

int main()
{
    jcc_auto str = JCC_UNWRAP(jcc_string_from_cstr(JCC_VERSION));
    jcc_log(JCC_LOG_INFO, JCC_CODE_LOCATION_ANY(), str.value);
    return 0;
}
