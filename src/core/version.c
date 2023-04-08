#include <jcc/version.h>
#include <jcc/logs.h>
#include <jcc/platform.h>
#include INTERFACE(STRING)
#include INTERFACE(MEMORY)

void jcc_register_component(const char *name, const char *version)
{
    const char fmt[] = "Registered component `%s` with version: %s";
    jcc_size_t size = CALL(STRING, STRLEN, name) + CALL(STRING, STRLEN, version) + sizeof(fmt);
    char *tmp = CALL(MEMORY, STACK_ALLOC, size);
    CALL(STRING, FORMAT, tmp, fmt, name, version);
    LOG_DEBUG(tmp);
}
