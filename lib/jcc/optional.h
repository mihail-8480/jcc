#pragma once
#include "numeric.h"
#include "macros.h"
#include "auto.h"
#include "error.h"

#define OPTIONAL_TYPE struct _ret_type_##__T__

#define OPTIONAL                                \
    struct EXPAND_AND_CONCAT(_ret_type_, __T__) \
    {                                           \
        bool has_value;                         \
        __T__ value;                            \
    }

#define OPTIONAL_VOID     \
    struct _ret_type_void \
    {                     \
        bool has_value;   \
        void *value;      \
    }

#define SOME_VOID ((struct EXPAND_AND_CONCAT(_ret_type_, __T__)){.has_value = true})
#define UNWRAP(...) ({ AUTO _retval = (__VA_ARGS__); AUTO _val = _retval.value; if(!_retval.has_value) { PANIC("The expression `" EXPAND_AND_STRINGIFY(__VA_ARGS__) "` did not return a value"); }  _val; })
#define SOME(...) ((struct EXPAND_AND_CONCAT(_ret_type_, __T__)){.value = (__T__)(__VA_ARGS__), .has_value = true})
#define NONE ((struct EXPAND_AND_CONCAT(_ret_type_, __T__)){.has_value = false})
#define NONE_IF_NULL(...) ({ AUTO _retval = (__VA_ARGS__); if (_retval == (void*)0) { return NONE; } })
#define TRY(...) ({ AUTO _retval = (__VA_ARGS__); if (!_retval.has_value) { return NONE; }; _retval.value; })
