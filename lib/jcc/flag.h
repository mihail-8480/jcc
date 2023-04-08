#pragma once
#define FLAG_VALUE(__idx__) (1 << __idx__)
#define FLAG(__id__, __idx__) __id__ = FLAG_VALUE(__idx__)
#define HAS_FLAG(__var__, __value__) ((__var__) & (__value__))
