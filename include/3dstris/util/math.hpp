#pragma once

#include <type_traits>

// python-like modulo, which makes negative numbers wrap around
template <typename T>
constexpr T mod(T a, T b) {
	static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");

	return (b + (a % b)) % b;
}

template <typename T>
struct Vector2 {
	static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");

	constexpr Vector2(const T x, const T y) : x(x), y(y) {}
	constexpr Vector2() {}

	T x = 0;
	T y = 0;
};

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

using Pos = Vector2f;
using WH = Vector2f;
