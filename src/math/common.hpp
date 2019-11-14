#pragma once

namespace math {
    template <typename T> static inline constexpr auto sq(T num) { return num * num; }
    template <typename T> static inline constexpr auto cb(T num) { return num * num * num; }
} // namespace math
