#pragma once
#include "numeric.h"
#include "macros.h"
#include "auto.h"
#include "error.h"

#define JCC_OPTIONAL_TYPE struct _ret_type_##__T__

#define JCC_OPTIONAL                                \
    struct JCC_EXPAND_AND_CONCAT(_ret_type_, __T__) \
    {                                               \
        bool has_value;                             \
        __T__ value;                                \
    }

#define JCC_VOID_OPTIONAL \
    struct _ret_type_void \
    {                     \
        bool has_value;   \
        void *value;      \
    }

#define JCC_UNWRAP(...) ({ jcc_auto _retval = (__VA_ARGS__); jcc_auto _val = _retval.value; if(!_retval.has_value) { JCC_THROW("The expression `" JCC_EXPAND_AND_STRINGIFY(__VA_ARGS__) "` did not return a value"); }  _val; })
#define JCC_SOME(...) ((struct JCC_EXPAND_AND_CONCAT(_ret_type_, __T__)){.value = (__T__)(__VA_ARGS__), .has_value = true})
#define JCC_NONE ((struct JCC_EXPAND_AND_CONCAT(_ret_type_, __T__)){.has_value = false})
#define JCC_NONE_IF_NULL(...) ({ jcc_auto _retval = (__VA_ARGS__); if (_retval == (void*)0) { return JCC_NONE; } })
#define JCC_TRY(...) ({ jcc_auto _retval = (__VA_ARGS__); if (!_retval.has_value) { return JCC_NONE; }; _retval.value; })
