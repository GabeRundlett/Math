#pragma once

#include "Common.hpp"

namespace Math {
    template <typename Precision> static inline constexpr Precision trigSeries(Precision x) { return trigSeries<float>(x); }
    template <> inline constexpr float trigSeries<float>(float x) {
        x = modHalfPi<float>(x);
        const auto x2 = sq(x);
        // clang-format off
        return x * (1.f -
            x2 * (oneOver<float>(FACTORIAL<3>) +
            x2 * (oneOver<float>(FACTORIAL<5>) -
            x2 * (oneOver<float>(FACTORIAL<7>)
            )))); // clang-format on
    }
    template <> inline constexpr double trigSeries<double>(double x) {
        x = modHalfPi<double>(x);
        const auto x2 = sq(x);
        // clang-format off
        return x * (1.0 -
            x2 * (oneOver<double>(FACTORIAL<3>) +
            x2 * (oneOver<double>(FACTORIAL<5>) -
            x2 * (oneOver<double>(FACTORIAL<7>) +
            x2 * (oneOver<double>(FACTORIAL<11>) -
            x2 * (oneOver<double>(FACTORIAL<13>) +
            x2 * (oneOver<double>(FACTORIAL<15>) -
            x2 * (oneOver<double>(FACTORIAL<17>)
            )))))))); // clang-format on
    }
    template <> inline constexpr long double trigSeries<long double>(long double x) {
        x = modHalfPi<long double>(x);
        const auto x2 = sq(x);
        // clang-format off
        return x * (1.0L - 
            x2 * (oneOver<long double>(FACTORIAL<3>) +
            x2 * (oneOver<long double>(FACTORIAL<5>) -
            x2 * (oneOver<long double>(FACTORIAL<7>) +
            x2 * (oneOver<long double>(FACTORIAL<11>) -
            x2 * (oneOver<long double>(FACTORIAL<13>) +
            x2 * (oneOver<long double>(FACTORIAL<15>) -
            x2 * (oneOver<long double>(FACTORIAL<17>) +
            x2 * (oneOver<long double>(FACTORIAL<19>) -
            x2 * (oneOver<long double>(FACTORIAL<21>) +
            x2 * (oneOver<long double>(FACTORIAL<23>) -
            x2 * (oneOver<long double>(FACTORIAL<25>)
            )))))))))))); // clang-format on
    }

    template <typename Precision> static inline constexpr auto sin(Precision x) {
        if (x < 0) {
            x *= -1;
            if (modTau<Precision>(x) > PI) {
                if (modPi<Precision>(x) > HALF_PI) return -trigSeries(-x);
                return trigSeries(x);
            } else if (modPi<Precision>(x) > HALF_PI)
                return trigSeries(-x);
            return -trigSeries(x);
        } else if (modTau<Precision>(x) > PI) {
            if (modPi<Precision>(x) > HALF_PI) return trigSeries(-x);
            return -trigSeries(x);
        } else if (modPi<Precision>(x) > HALF_PI)
            return -trigSeries(-x);
        return trigSeries(x);
    }

    template <typename Precision> static inline constexpr auto cos(Precision x) {
        if (x < 0) x *= -1;
        if (modTau<Precision>(x) > PI) {
            if (modPi<Precision>(x) > HALF_PI) return trigSeries(x);
            return trigSeries(-x);
        } else if (modPi<Precision>(x) > HALF_PI)
            return -trigSeries(x);
        if (x == 0) return 1;
        return -trigSeries(-x);
    }

    template <typename Precision> static inline constexpr auto tan(Precision x) {
        if (x < 0) {
            x *= -1;
            if (modTau<Precision>(x) > PI) {
                if (modPi<Precision>(x) > HALF_PI) return -trigSeries(-x) / trigSeries(x);
                return trigSeries(x) / trigSeries(-x);
            } else if (modPi<Precision>(x) > HALF_PI)
                return trigSeries(-x) / -trigSeries(x);
            if (x == 0.0) return -trigSeries(x);
            return trigSeries(x) / trigSeries(-x);
        } else if (modTau<Precision>(x) > PI) {
            if (modPi<Precision>(x) > HALF_PI) return trigSeries(-x) / trigSeries(x);
            return -trigSeries(x) / trigSeries(-x);
        } else if (modPi<Precision>(x) > HALF_PI)
            return trigSeries(-x) / trigSeries(x);
        if (x == 0.0) return trigSeries(x);
        return trigSeries(x) / -trigSeries(-x);
    }
} // namespace Math
