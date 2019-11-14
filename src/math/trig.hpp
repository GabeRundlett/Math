#pragma once

namespace math {
    static constexpr auto PI = 3.141592653589793238L, TAU = 6.283185307179586476L, HALF_PI = 1.570796326794896619L,
                          ONE_OVER_PI = 0.318309886183790671L, ONE_OVER_TAU = 0.159154943091895335L,
                          ONE_OVER_HALF_PI = 0.636619772367581343L, DEG_TO_RAD = TAU / 360.0L, RAD_TO_DEG = 360.0L / TAU,
                          ONE_OVER_3F = -1.66666666666666666666e-01L, ONE_OVER_5F = 8.33333333333333333333e-03L,
                          ONE_OVER_7F = -1.98412698412698412698e-04L, ONE_OVER_9F = 2.75573192239858906525e-06L,
                          ONE_OVER_11F = -2.50521083854417187750e-08L, ONE_OVER_13F = 1.60590438368216145993e-10L,
                          ONE_OVER_15F = -7.64716373181981647590e-13L, ONE_OVER_17F = 2.81145725434552076319e-15L;

    namespace _internal {
#define DMOD(x, m) (x < 0.0 ? (int)(x / m - 1) * m - x : x - (int)(x / m) * m)
#define DMOD_PI(x) (x < 0.0 ? (int)(x * ONE_OVER_PI - 1) * PI - x : x - (int)(x * ONE_OVER_PI) * PI)
#define DMOD_TAU(x) (x < 0.0 ? (int)(x * ONE_OVER_TAU - 1) * TAU - x : x - (int)(x * ONE_OVER_TAU) * TAU)
#define DMOD_HALF_PI(x) (x < 0.0 ? (int)(x * ONE_OVER_HALF_PI - 1) * HALF_PI - x : x - (int)(x * ONE_OVER_HALF_PI) * HALF_PI)

#define FMOD_PI(x) (x < 0.f ? (int)(x * (float)ONE_OVER_PI - 1) * (float)PI - x : x - (int)(x * (float)ONE_OVER_PI) * (float)PI)
#define FMOD_TAU(x)                                                                                                            \
    (x < 0.f ? (int)(x * (float)ONE_OVER_TAU - 1) * (float)TAU - x : x - (int)(x * (float)ONE_OVER_TAU) * (float)TAU)
#define FMOD_HALF_PI(x)                                                                                                        \
    (x < 0.f ? (int)(x * (float)ONE_OVER_HALF_PI - 1) * (float)HALF_PI - x                                                     \
             : x - (int)(x * (float)ONE_OVER_HALF_PI) * (float)HALF_PI)

#define SINE_IMPL_SWITCH(function, tmod_pi, tmod_tau)                                                                          \
    if (x < 0.0) {                                                                                                             \
        x *= -1.0;                                                                                                             \
        if (tmod_tau(x) > PI) {                                                                                                \
            if (tmod_pi(x) > HALF_PI) return -function(-x);                                                                    \
            return function(x);                                                                                                \
        } else if (tmod_pi(x) > HALF_PI)                                                                                       \
            return function(-x);                                                                                               \
        return -function(x);                                                                                                   \
    }                                                                                                                          \
    if (tmod_tau(x) > PI) {                                                                                                    \
        if (tmod_pi(x) > HALF_PI) return function(-x);                                                                         \
        return -function(x);                                                                                                   \
    } else if (tmod_pi(x) > HALF_PI)                                                                                           \
        return -function(-x);                                                                                                  \
    return function(x)

#define COSINE_IMPL_SWITCH(function, tmod_pi, tmod_tau)                                                                        \
    if (x < 0.0) x *= -1.0;                                                                                                    \
    if (tmod_tau(x) > PI) {                                                                                                    \
        if (tmod_pi(x) > HALF_PI) return function(x);                                                                          \
        return function(-x);                                                                                                   \
    } else if (tmod_pi(x) > HALF_PI)                                                                                           \
        return -function(x);                                                                                                   \
    if (x == 0.0) return 1.0;                                                                                                  \
    return -function(-x)

#define TANGENT_IMPL_SWITCH(function, tmod_pi, tmod_tau)                                                                       \
    if (x < 0.0) {                                                                                                             \
        x *= -1.0;                                                                                                             \
        if (tmod_tau(x) > PI) {                                                                                                \
            if (tmod_pi(x) > HALF_PI) return -function(-x) / function(x);                                                      \
            return function(x) / function(-x);                                                                                 \
        } else if (tmod_pi(x) > HALF_PI)                                                                                       \
            return function(-x) / -function(x);                                                                                \
        if (x == 0.0) return -function(x);                                                                                     \
        return function(x) / function(-x);                                                                                     \
    }                                                                                                                          \
    if (tmod_tau(x) > PI) {                                                                                                    \
        if (tmod_pi(x) > HALF_PI) return function(-x) / function(x);                                                           \
        return -function(x) / function(-x);                                                                                    \
    } else if (tmod_pi(x) > HALF_PI)                                                                                           \
        return function(-x) / function(x);                                                                                     \
    if (x == 0.0) return function(x);                                                                                          \
    return function(x) / -function(-x)

        static inline constexpr float trig_fast(float x) {
            x = FMOD_HALF_PI(x);
            const float x2 = x * x;
            return x * (1.f + x2 * ((float)ONE_OVER_3F + x2 * ((float)ONE_OVER_5F + x2 * (float)ONE_OVER_7F)));
        }

        static inline constexpr double trig(double x) {
            x = DMOD_HALF_PI(x);
            const double x2 = x * x;
            return x * (1.0 + x2 * (ONE_OVER_3F +
                                    x2 * (ONE_OVER_5F +
                                          x2 * (ONE_OVER_7F +
                                                x2 * (ONE_OVER_9F +
                                                      x2 * (ONE_OVER_11F +
                                                            x2 * (ONE_OVER_13F + x2 * (ONE_OVER_15F + x2 * ONE_OVER_17F))))))));
        }
    } // namespace _internal

    static inline constexpr double sin(double x) { SINE_IMPL_SWITCH(_internal::trig, DMOD_PI, DMOD_TAU); }
    static inline constexpr float sin(float x) { SINE_IMPL_SWITCH(_internal::trig_fast, FMOD_PI, FMOD_TAU); }

    static inline constexpr double cos(double x) { COSINE_IMPL_SWITCH(_internal::trig, DMOD_PI, DMOD_TAU); }
    static inline constexpr float cos(float x) { COSINE_IMPL_SWITCH(_internal::trig_fast, FMOD_PI, FMOD_TAU); }

    static inline constexpr double tan(double x) { TANGENT_IMPL_SWITCH(_internal::trig, DMOD_PI, DMOD_TAU); }
    static inline constexpr float tan(float x) { TANGENT_IMPL_SWITCH(_internal::trig_fast, FMOD_PI, FMOD_TAU); }
} // namespace math

#undef DMOD(x, m)
#undef DMOD_PI(x)
#undef DMOD_TAU(x)
#undef DMOD_HALF_PI(x)
#undef FMOD_PI(x)
#undef FMOD_TAU(x)
#undef FMOD_HALF_PI(x)

#undef SINE_IMPL_SWITCH(function, tmod_pi, tmod_tau)
#undef COSINE_IMPL_SWITCH(function, tmod_pi, tmod_tau)
#undef TANGENT_IMPL_SWITCH(function, tmod_pi, tmod_tau)
