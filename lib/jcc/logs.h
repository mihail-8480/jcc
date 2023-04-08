#pragma once
#include "code.h"
#define JCC_LOG_LEVEL_COUNT 3
typedef enum jcc_log_level
{
    JCC_LOG_LEVEL_ALL = 0,
    JCC_LOG_INFO = 1,
    JCC_LOG_WARNING = 2,
    JCC_LOG_ERROR = 3
} jcc_log_level_t;

typedef struct jcc_log_settings
{
    jcc_bool_t show_level;
    jcc_bool_t show_date;
    jcc_bool_t show_time;
    jcc_bool_t show_code_path;
    jcc_bool_t enable_color;
    jcc_bool_t append_newline;
} jcc_log_settings_t;

void jcc_log(jcc_log_level_t level, jcc_code_location_t location, const jcc_byte_t *message);
void jcc_log_set_fd_for_level(jcc_log_level_t level, jcc_int_t fd);
void jcc_log_set_settings(jcc_log_settings_t settings);
jcc_log_settings_t jcc_log_get_settings(void);

#define jcc_log_info(...) jcc_log(JCC_LOG_INFO, JCC_CODE_LOCATION_ANY(), (__VA_ARGS__))
#define jcc_log_warning(...) jcc_log(JCC_LOG_WARNING, JCC_CODE_LOCATION_ANY(), (__VA_ARGS__))
#define jcc_log_error(...) jcc_log(JCC_LOG_ERROR, JCC_CODE_LOCATION_ANY(), (__VA_ARGS__))