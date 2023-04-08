#include <jcc/error.h>
#include <jcc/platform.h>
#include JCC_INTERFACE(error)

void jcc_abort(void)
{
    JCC_CALL(ERROR, ABORT);
}