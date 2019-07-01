static constexpr double PI = 3.141592653589793238, TAU = 6.283185307179586476, HALF_PI = 1.570796326794896619,
                        COEL_MATH_ONE_OVER_PI = 0.318309886183790671, COEL_MATH_ONE_OVER_TAU = 0.159154943091895335,
                        COEL_MATH_ONE_OVER_HALF_PI = 0.636619772367581343, COEL_MATH_ONE_OVER_3F = -1.66666666666666666666e-01,
                        COEL_MATH_ONE_OVER_5F = 8.33333333333333333333e-03, COEL_MATH_ONE_OVER_7F = -1.98412698412698412698e-04,
                        COEL_MATH_ONE_OVER_9F = 2.75573192239858906525e-06,
                        COEL_MATH_ONE_OVER_11F = -2.50521083854417187750e-08,
                        COEL_MATH_ONE_OVER_13F = 1.60590438368216145993e-10,
                        COEL_MATH_ONE_OVER_15F = -7.64716373181981647590e-13,
                        COEL_MATH_ONE_OVER_17F = 2.81145725434552076319e-15;

#define SQ(x) (x * x)
#define CB(x) (x * x * x)
#define X_4TH(x) (x * x * x * x)
#define X_5TH(x) (x * x * x * x * x)

#define DMOD(x, m) (x < 0.0 ? (int)(x / m - 1) * m - x : x - (int)(x / m) * m)
#define DMOD_PI(x) (x < 0.0 ? (int)(x * COEL_MATH_ONE_OVER_PI - 1) * PI - x : x - (int)(x * COEL_MATH_ONE_OVER_PI) * PI)
#define DMOD_TAU(x) (x < 0.0 ? (int)(x * COEL_MATH_ONE_OVER_TAU - 1) * TAU - x : x - (int)(x * COEL_MATH_ONE_OVER_TAU) * TAU)
#define DMOD_HALF_PI(x)                                                                                                        \
    (x < 0.0 ? (int)(x * COEL_MATH_ONE_OVER_HALF_PI - 1) * HALF_PI - x : x - (int)(x * COEL_MATH_ONE_OVER_HALF_PI) * HALF_PI)

#define FMOD(x, m) (x < 0.f ? (int)(x / m - 1) * m - x : x - (int)(x / m) * m)
#define FMOD_PI(x)                                                                                                             \
    (x < 0.f ? (int)(x * (float)COEL_MATH_ONE_OVER_PI - 1) * (float)PI - x                                                     \
             : x - (int)(x * (float)COEL_MATH_ONE_OVER_PI) * (float)PI)
#define FMOD_TAU(x)                                                                                                            \
    (x < 0.f ? (int)(x * (float)COEL_MATH_ONE_OVER_TAU - 1) * (float)TAU - x                                                   \
             : x - (int)(x * (float)COEL_MATH_ONE_OVER_TAU) * (float)TAU)
#define FMOD_HALF_PI(x)                                                                                                        \
    (x < 0.f ? (int)(x * (float)COEL_MATH_ONE_OVER_HALF_PI - 1) * (float)HALF_PI - x                                           \
             : x - (int)(x * (float)COEL_MATH_ONE_OVER_HALF_PI) * (float)HALF_PI)

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define ABS(x) (x < 0 ? -x : x)
#define SIGN(x) (x < 0 ? -1 : 1)

#define QWORD_HI_DWORD(x) (*(int *)&x)
#define QWORD_LO_DWORD(x) (*((int *)&x + 1))

#define SINE_IMPL_SWITCH(function, tmod_pi, tmod_tau)                                                                          \
    if (x < 0.0) {                                                                                                             \
        x *= -1.0;                                                                                                             \
        if (tmod_tau(x) > PI) {                                                                                                \
            if (tmod_pi(x) > HALF_PI)                                                                                          \
                return -function(-x);                                                                                          \
            return function(x);                                                                                                \
        } else if (tmod_pi(x) > HALF_PI)                                                                                       \
            return function(-x);                                                                                               \
        return -function(x);                                                                                                   \
    }                                                                                                                          \
    if (tmod_tau(x) > PI) {                                                                                                    \
        if (tmod_pi(x) > HALF_PI)                                                                                              \
            return function(-x);                                                                                               \
        return -function(x);                                                                                                   \
    } else if (tmod_pi(x) > HALF_PI)                                                                                           \
        return -function(-x);                                                                                                  \
    return function(x)

#define COSINE_IMPL_SWITCH(function, tmod_pi, tmod_tau)                                                                        \
    if (x < 0.0)                                                                                                               \
        x *= -1.0;                                                                                                             \
    if (tmod_tau(x) > PI) {                                                                                                    \
        if (tmod_pi(x) > HALF_PI)                                                                                              \
            return function(x);                                                                                                \
        return function(-x);                                                                                                   \
    } else if (tmod_pi(x) > HALF_PI)                                                                                           \
        return -function(x);                                                                                                   \
    if (x == 0.0)                                                                                                              \
        return 1.0;                                                                                                            \
    return -function(-x)

#define TANGENT_IMPL_SWITCH(function, tmod_pi, tmod_tau)                                                                       \
    if (x < 0.0) {                                                                                                             \
        x *= -1.0;                                                                                                             \
        if (tmod_tau(x) > PI) {                                                                                                \
            if (tmod_pi(x) > HALF_PI)                                                                                          \
                return -function(-x) / function(x);                                                                            \
            return function(x) / function(-x);                                                                                 \
        } else if (tmod_pi(x) > HALF_PI)                                                                                       \
            return function(-x) / -function(x);                                                                                \
        if (x == 0.0)                                                                                                          \
            return -function(x);                                                                                               \
        return function(x) / function(-x);                                                                                     \
    }                                                                                                                          \
    if (tmod_tau(x) > PI) {                                                                                                    \
        if (tmod_pi(x) > HALF_PI)                                                                                              \
            return function(-x) / function(x);                                                                                 \
        return -function(x) / function(-x);                                                                                    \
    } else if (tmod_pi(x) > HALF_PI)                                                                                           \
        return function(-x) / function(x);                                                                                     \
    if (x == 0.0)                                                                                                              \
        return function(x);                                                                                                    \
    return function(x) / -function(-x)

namespace Math {
constexpr static inline float internal_trig_fast(float x) {
    x = FMOD_HALF_PI(x);
    const float xSQ = x * x;
    return x * (1.f + xSQ * ((float)COEL_MATH_ONE_OVER_3F +
                             xSQ * ((float)COEL_MATH_ONE_OVER_5F + xSQ * (float)COEL_MATH_ONE_OVER_7F)));
}

constexpr static inline double internal_trig(double x) {
    x = DMOD_HALF_PI(x);
    const double xSQ = x * x;
    return x * (1.0 +
                xSQ * (COEL_MATH_ONE_OVER_3F +
                       xSQ * (COEL_MATH_ONE_OVER_5F +
                              xSQ * (COEL_MATH_ONE_OVER_7F +
                                     xSQ * (COEL_MATH_ONE_OVER_9F +
                                            xSQ * (COEL_MATH_ONE_OVER_11F +
                                                   xSQ * (COEL_MATH_ONE_OVER_13F +
                                                          xSQ * (COEL_MATH_ONE_OVER_15F + xSQ * COEL_MATH_ONE_OVER_17F))))))));
}

double sin(double x) { SINE_IMPL_SWITCH(internal_trig, DMOD_PI, DMOD_TAU); }
float sin(float x) { SINE_IMPL_SWITCH(internal_trig_fast, FMOD_PI, FMOD_TAU); }

double cos(double x) { COSINE_IMPL_SWITCH(internal_trig, DMOD_PI, DMOD_TAU); }
float cos(float x) { COSINE_IMPL_SWITCH(internal_trig_fast, FMOD_PI, FMOD_TAU); }

double tan(double x) { TANGENT_IMPL_SWITCH(internal_trig, DMOD_PI, DMOD_TAU); }
float tan(float x) { TANGENT_IMPL_SWITCH(internal_trig_fast, FMOD_PI, FMOD_TAU); }
} // namespace Math
