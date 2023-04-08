#pragma once
#define JCC_STRINGIFY(__value__) #__value__
#define JCC_EXPAND_AND_STRINGIFY(__value__) JCC_STRINGIFY(__value__)
#define JCC_CONCAT(__a__, __b__) __a__##__b__
#define JCC_EXPAND_AND_CONCAT(__a__, __b__) JCC_CONCAT(__a__, __b__)