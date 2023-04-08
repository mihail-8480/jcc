#pragma once
#include "logs.h"

void jcc_abort(void);

#define PANIC(...) ({ LOG_ERR(__VA_ARGS__); jcc_abort(); })