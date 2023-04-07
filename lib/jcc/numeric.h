#pragma once

typedef unsigned long int jcc_size_t;

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