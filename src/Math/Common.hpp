#pragma once

#include "Constants.hpp"

namespace Math {
    template <typename Precision> static inline constexpr auto sq(const Precision val) { return val * val; }
    template <typename Precision> static inline constexpr auto cb(const Precision val) { return val * val * val; }
    template <typename PrecisionOut, typename PrecisionIn> static inline constexpr PrecisionOut oneOver(const PrecisionIn val) {
        return static_cast<PrecisionOut>(1) / val;
    }

    template <unsigned long long Constant> inline constexpr unsigned long long factorial() { return factorial<Constant - 1>(); }
    template <> inline constexpr unsigned long long factorial<0>() { return 1; }

    template <typename PrecisionOut, typename PrecisionInX, typename PrecisionInM>
    static inline constexpr auto modulo(const PrecisionInX x, const PrecisionInM m) {
        if (x < static_cast<PrecisionInX>(0))
            return static_cast<double>(static_cast<int>(x * oneOver<PrecisionOut>(m) - 1) * m - x);
        else
            return static_cast<double>(x - static_cast<int>(x * oneOver<PrecisionOut>(m)) * m);
    }
    template <typename PrecisionOut, typename PrecisionInX> static inline constexpr PrecisionOut modTau(const PrecisionInX x) {
        if (x < static_cast<PrecisionInX>(0))
            return static_cast<double>(static_cast<int>(x * oneOver<PrecisionOut>(TAU) - 1) * TAU - x);
        else
            return static_cast<double>(x - static_cast<int>(x * oneOver<PrecisionOut>(TAU)) * TAU);
    }
    template <typename PrecisionOut, typename PrecisionInX> static inline constexpr PrecisionOut modPi(const PrecisionInX x) {
        if (x < static_cast<PrecisionInX>(0))
            return static_cast<double>(static_cast<int>(x * oneOver<PrecisionOut>(PI) - 1) * PI - x);
        else
            return static_cast<double>(x - static_cast<int>(x * oneOver<PrecisionOut>(PI)) * PI);
    }
    template <typename PrecisionOut, typename PrecisionInX>
    static inline constexpr PrecisionOut modHalfPi(const PrecisionInX x) {
        if (x < static_cast<PrecisionInX>(0))
            return static_cast<double>(static_cast<int>(x * oneOver<PrecisionOut>(HALF_PI) - 1) * HALF_PI - x);
        else
            return static_cast<double>(x - static_cast<int>(x * oneOver<PrecisionOut>(HALF_PI)) * HALF_PI);
    }
} // namespace Math
