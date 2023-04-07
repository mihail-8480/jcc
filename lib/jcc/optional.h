#pragma once
#include "numeric.h"
#include "macros.h"

#define JCC_OPTIONAL_TYPE(__T__) struct _ret_type_##__T__

#define JCC_OPTIONAL(__T__)  \
    struct _ret_type_##__T__ \
    {                        \
        bool has_value;      \
        __T__ value;         \
    }

#define JCC_VOID_OPTIONAL \
    struct _ret_type_void \
    {                     \
        bool has_value;   \
        void *value;      \
    }

#define JCC_TRY(__T__, ...) ({ __auto_type _retval = (__VA_ARGS__); if (!_retval.has_value) { return JCC_NONE(__T__); }; _retval.value; })
#define JCC_SOME(__T__, ...) ((struct _ret_type_##__T__){.value = (__T__)__VA_ARGS__, .has_value = true})
#define JCC_NONE(__T__) ((struct _ret_type_##__T__){.has_value = false})