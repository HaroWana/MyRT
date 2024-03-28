#ifndef NUMDIGITS_HPP
# define NUMDIGITS_HPP

#include <climits>
#include <cstdint>

template <class T>
int numDigits(T number);

template <>
int numDigits(int64_t x);

template<>
int numDigits(int32_t x);

template <>
int numDigits(char n);

#endif