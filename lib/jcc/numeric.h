#pragma once

typedef char jcc_byte_t;
typedef unsigned char jcc_ubyte_t;
typedef unsigned int jcc_uint_t;
typedef int jcc_int_t;
typedef unsigned long jcc_ulong_t;
typedef long jcc_long_t;
typedef unsigned short jcc_ushort_t;
typedef short jcc_short_t;
typedef jcc_ulong_t jcc_size_t;

#ifndef __bool_true_false_are_defined
typedef enum
{
    false = 0,
    true = 1
} jcc_bool_t;
#define bool jcc_bool_t
#else
typedef bool jcc_bool_t;
#endif