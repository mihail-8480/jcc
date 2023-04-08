#pragma once
#include "logs.h"

void jcc_abort(void);

#define JCC_THROW(...) ({ jcc_log_error(__VA_ARGS__); jcc_abort(); })