#pragma once
#include "code.h"
#define LOG_LEVEL_COUNT 5
typedef enum jcc_log_level
{
    LOG_LEVEL_ALL = 0,
    LOG_DEBUG = 1,
    LOG_INFO = 2,
    LOG_FIXME = 3,
    LOG_WARNING = 4,
    LOG_ERROR = 5,
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

typedef void jcc_log_handler_t(jcc_log_level_t level, jcc_code_location_t location, const jcc_byte_t *message);

void jcc_log(jcc_log_level_t level, jcc_code_location_t location, const jcc_byte_t *message);
void jcc_log_set_fd_for_level(jcc_log_level_t level, jcc_int_t fd);
void jcc_log_set_settings(jcc_log_settings_t settings);
jcc_bool_t jcc_log_add_handler(jcc_log_handler_t handler);
jcc_bool_t jcc_log_remove_handler(jcc_log_handler_t handler);
jcc_log_settings_t jcc_log_get_settings(void);
void jcc_log_set_level(jcc_log_level_t level);

#define LOG_DEBUG(...) jcc_log(LOG_DEBUG, CODE_LOCATION_ANY(), (__VA_ARGS__))
#define LOG(...) jcc_log(LOG_INFO, CODE_LOCATION_ANY(), (__VA_ARGS__))
#define LOG_WARN(...) jcc_log(LOG_WARNING, CODE_LOCATION_ANY(), (__VA_ARGS__))
#define LOG_ERR(...) jcc_log(LOG_ERROR, CODE_LOCATION_ANY(), (__VA_ARGS__))
#define FIXME(...) jcc_log(LOG_FIXME, CODE_LOCATION_ANY(), (__VA_ARGS__))