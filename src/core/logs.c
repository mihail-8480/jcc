#include <jcc/platform.h>
#include JCC_INTERFACE(file)
#include JCC_INTERFACE(time)
#include JCC_INTERFACE(terminal_colors)

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

jcc_int_t log_fds[JCC_LOG_LEVEL_COUNT] = {JCC_FD_OUT,
                                          JCC_FD_ERR,
                                          JCC_FD_ERR};

const jcc_byte_t *log_names[] = {"INFO", "WARNING", "ERROR"};

static inline jcc_int_t get_offset(jcc_log_level_t level)
{
    if (level <= 0)
    {
        return 0;
    }
    if (level > JCC_LOG_LEVEL_COUNT)
    {
        return 0;
    }
    return level - 1;
}

void jcc_log(jcc_log_level_t level, jcc_code_location_t location, const jcc_byte_t *message)
{
    jcc_int_t offset = get_offset(level);
    jcc_auto stream = JCC_INTERFACE_FILE_GET_NATIVE_STREAM_FROM_FD(log_fds[offset], "a");
    jcc_auto now = JCC_INTERFACE_TIME_NOW();

    if (log_settings.show_date)
    {
        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_DIM ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_MAGENTA));
        }

        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "%02d:%02d:%02d ",
                                          JCC_INTERFACE_TIME_YEAR(now),
                                          JCC_INTERFACE_TIME_MONTH(now),
                                          JCC_INTERFACE_TIME_DAY(now));

        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_FORMAT_RESET);
        }
    }

    if (log_settings.show_time)
    {
        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_DIM ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_MAGENTA));
        }

        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "%02d:%02d:%02d ",
                                          JCC_INTERFACE_TIME_HOUR(now),
                                          JCC_INTERFACE_TIME_MINUTE(now),
                                          JCC_INTERFACE_TIME_SECOND(now));
        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_FORMAT_RESET);
        }
    }

    if (log_settings.show_code_path)
    {
        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_DIM ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_BLUE));
        }
        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "[");

        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_BRIGHT));
        }
        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "%s() ",
                                          location.function_name);

        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_FORMAT_RESET);
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_UNDERSCORE ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_BLUE));
        }
        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "%s:%d",
                                          location.file_name,
                                          location.file_line);

        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_FORMAT_RESET);
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_DIM ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_BLUE));
        }

        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "] ");

        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_FORMAT_RESET);
        }
    }

    if (log_settings.show_level)
    {
        if (log_settings.enable_color)
        {
            switch (level)
            {
            case JCC_LOG_WARNING:
                JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_BRIGHT ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_YELLOW));
                break;
            case JCC_LOG_ERROR:
                JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_BRIGHT ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_RED));
                break;
            default:
                JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_COLOR_ESCAPE_SEQ(JCC_INTERFACE_TERMINAL_COLORS_GEN_FORMAT_BRIGHT ";" JCC_INTERFACE_TERMINAL_COLORS_FOREGROUND_COL_GREEN));
                break;
            }
        }

        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "%s ", log_names[offset]);
        if (log_settings.enable_color)
        {
            JCC_INTERFACE_FILE_FORMATED_PRINT(stream, JCC_INTERFACE_TERMINAL_COLORS_SHELL_FORMAT_RESET);
        }
    }

    JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "%s", message);

    if (log_settings.append_newline)
    {
        JCC_INTERFACE_FILE_FORMATED_PRINT(stream, "\n");
    }
    JCC_INTERFACE_FILE_CLOSE_NATIVE_STREAM(stream);
}

void jcc_log_set_fd_for_level(jcc_log_level_t level, jcc_int_t fd)
{
    if (level == 0)
    {
        for (jcc_int_t i = 0; i < JCC_LOG_LEVEL_COUNT; i++)
        {
            log_fds[i] = fd;
        }
        return;
    }
    jcc_int_t offset = get_offset(level);
    log_fds[offset] = fd;
}
