#include <jcc/version.h>
#include <jcc/string.h>

int i = 0;

void log_handler([[maybe_unused]] jcc_log_level_t level, [[maybe_unused]] jcc_code_location_t location, [[maybe_unused]] const jcc_byte_t *message)
{
    i++;
}

int main()
{
    jcc_log_add_handler(log_handler);
    LOG("Version: " VERSION);
    return i;
}
