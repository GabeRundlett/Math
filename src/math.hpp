#pragma once

namespace math {
    template <typename T> static inline constexpr T sq(T num) { return num * num; }
    template <typename T> static inline constexpr T cb(T num) { return num * num * num; }
} // namespace math

#include "math/trig.hpp"
#include "math/types.hpp"
