#pragma once

#include <time.h>

#define INTERFACE_TIME_NOW() ({ time_t _timestamp; struct tm *_timeinfo; time (&_timestamp); _timeinfo = localtime(&_timestamp); _timeinfo; })
#define INTERFACE_TIME_YEAR(__tm__) ((__tm__)->tm_year + 1900)
#define INTERFACE_TIME_MONTH(__tm__) ((__tm__)->tm_mon + 1)
#define INTERFACE_TIME_DAY(__tm__) ((__tm__)->tm_mday)
#define INTERFACE_TIME_HOUR(__tm__) ((__tm__)->tm_hour)
#define INTERFACE_TIME_MINUTE(__tm__) ((__tm__)->tm_min)
#define INTERFACE_TIME_SECOND(__tm__) ((__tm__)->tm_sec)