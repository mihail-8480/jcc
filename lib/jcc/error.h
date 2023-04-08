#pragma once
#include "logs.h"

void jcc_abort(void);

#define JCC_THROW(...) ({ jcc_log(JCC_LOG_ERROR, JCC_CODE_LOCATION_ANY(), (__VA_ARGS__)); jcc_abort(); })