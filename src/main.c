#include <jcc/version.h>
#include <jcc/compiler/compiler.h>


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    LOG_DEBUG("Version: " VERSION);
    FIXME("Move this to a compiler function");
    AUTO context = UNWRAP(jcc_get_file_context("src/main.c"));
    jcc_optional_token_t token;
    do
    {
        token = jcc_token_next(&context.lexer);

    } while (token.has_value);
}
