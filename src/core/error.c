#include <jcc/error.h>
#include <jcc/platform.h>
#include INTERFACE(ERROR)

void jcc_abort(void)
{
    CALL(ERROR, ABORT);
}