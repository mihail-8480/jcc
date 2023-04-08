#include <jcc/platform.h>
#include INTERFACE(FILE)
#include INTERFACE(TIME)
#include INTERFACE(TERMINAL_COLORS)

#include <jcc/logs.h>
#include <jcc/auto.h>

jcc_log_settings_t log_settings = {.show_code_path = true,
                                   .show_date = true,
                                   .show_level = true,
                                   .show_time = true,
                                   .enable_color = true,
                                   .append_newline = true};

void jcc_log_set_settings(jcc_log_settings_t settings)
{
    log_settings = settings;
}

jcc_log_settings_t jcc_log_get_settings(void)
{
    return log_settings;
}

jcc_int_t log_fds[LOG_LEVEL_COUNT] = {CONST(FILE, FD_OUT),
                                      CONST(FILE, FD_ERR),
                                      CONST(FILE, FD_ERR)};

const jcc_byte_t *log_names[] = {"INFO", "WARNING", "ERROR"};

static inline jcc_int_t get_offset(jcc_log_level_t level)
{
    if (level <= 0)
    {
        return 0;
    }
    if (level > LOG_LEVEL_COUNT)
    {
        return 0;
    }
    return level - 1;
}

void jcc_log(jcc_log_level_t level, jcc_code_location_t location, const jcc_byte_t *message)
{
    jcc_int_t offset = get_offset(level);
    jcc_auto stream = CALL(FILE, GET_NATIVE_STREAM_FROM_FD, log_fds[offset], "a");
    jcc_auto now = CALL(TIME, NOW);

    if (log_settings.show_date)
    {
        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_DIM) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_MAGENTA)));
        }

        CALL(FILE, FORMAT_PRINT, stream, "%02d:%02d:%02d ", CALL(TIME, YEAR, now), CALL(TIME, MONTH, now), CALL(TIME, DAY, now));

        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CONST(TERMINAL_COLORS, SHELL_FORMAT_RESET));
        }
    }

    if (log_settings.show_time)
    {
        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_DIM) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_MAGENTA)));
        }

        CALL(FILE, FORMAT_PRINT, stream, "%02d:%02d:%02d ", CALL(TIME, HOUR, now), CALL(TIME, MINUTE, now), CALL(TIME, SECOND, now));

        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CONST(TERMINAL_COLORS, SHELL_FORMAT_RESET));
        }
    }

    if (log_settings.show_code_path)
    {
        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_DIM) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_BLUE)));
        }
        CALL(FILE, FORMAT_PRINT, stream, "[");

        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_BRIGHT)));
        }
        CALL(FILE, FORMAT_PRINT, stream, "%s() ", location.function_name);

        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CONST(TERMINAL_COLORS, SHELL_FORMAT_RESET));
            CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_UNDERSCORE) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_BLUE)));
        }
        CALL(FILE, FORMAT_PRINT, stream, "%s:%d", location.file_name, location.file_line);

        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CONST(TERMINAL_COLORS, SHELL_FORMAT_RESET));
            CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_DIM) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_BLUE)));
        }

        CALL(FILE, FORMAT_PRINT, stream, "] ");

        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CONST(TERMINAL_COLORS, SHELL_FORMAT_RESET));
        }
    }

    if (log_settings.show_level)
    {
        if (log_settings.enable_color)
        {
            switch (level)
            {
            case LOG_WARNING:
                CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_BRIGHT) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_YELLOW)));
                break;
            case LOG_ERROR:
                CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_BRIGHT) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_RED)));
                break;
            default:
                CALL(FILE, FORMAT_PRINT, stream, CALL(TERMINAL_COLORS, SHELL_COLOR_ESCAPE_SEQ, CONST(TERMINAL_COLORS, GEN_FORMAT_BRIGHT) ";" CONST(TERMINAL_COLORS, FOREGROUND_COL_GREEN)));
                break;
            }
        }

        CALL(FILE, FORMAT_PRINT, stream, "%s ", log_names[offset]);
        if (log_settings.enable_color)
        {
            CALL(FILE, FORMAT_PRINT, stream, CONST(TERMINAL_COLORS, SHELL_FORMAT_RESET));
        }
    }

    CALL(FILE, FORMAT_PRINT, stream, "%s", message);
    if (log_settings.append_newline)
    {
        CALL(FILE, FORMAT_PRINT, stream, "\n");
    }

    CALL(FILE, CLOSE_NATIVE_STREAM, stream);
}

void jcc_log_set_fd_for_level(jcc_log_level_t level, jcc_int_t fd)
{
    if (level == 0)
    {
        for (jcc_int_t i = 0; i < LOG_LEVEL_COUNT; i++)
        {
            log_fds[i] = fd;
        }
        return;
    }
    jcc_int_t offset = get_offset(level);
    log_fds[offset] = fd;
}
