#pragma once

#include <time.h>

#define JCC_INTERFACE_TIME_NOW() ({ time_t _timestamp; struct tm *_timeinfo; time (&_timestamp); _timeinfo = localtime(&_timestamp); _timeinfo; })
#define JCC_INTERFACE_TIME_YEAR(__tm__) ((__tm__)->tm_year + 1900)
#define JCC_INTERFACE_TIME_MONTH(__tm__) ((__tm__)->tm_mon + 1)
#define JCC_INTERFACE_TIME_DAY(__tm__) ((__tm__)->tm_mday)
#define JCC_INTERFACE_TIME_HOUR(__tm__) ((__tm__)->tm_hour)
#define JCC_INTERFACE_TIME_MINUTE(__tm__) ((__tm__)->tm_min)
#define JCC_INTERFACE_TIME_SECOND(__tm__) ((__tm__)->tm_sec)