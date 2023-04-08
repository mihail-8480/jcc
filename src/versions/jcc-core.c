#include <jcc/version.h>
__attribute__((constructor)) static void init()
{
    jcc_register_component("jcc-core", VERSION_FULL);
}