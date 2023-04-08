#pragma once
#define STRINGIFY(__value__) #__value__
#define EXPAND_AND_STRINGIFY(__value__) STRINGIFY(__value__)
#define CONCAT(__a__, __b__) __a__##__b__
#define EXPAND_AND_CONCAT(__a__, __b__) CONCAT(__a__, __b__)