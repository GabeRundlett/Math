#pragma once

namespace math {
static constexpr double PI = 3.141592653589793238, TAU = 6.283185307179586476, HALF_PI = 1.570796326794896619,
                        ONE_OVER_PI = 0.318309886183790671, ONE_OVER_TAU = 0.159154943091895335, DEG_TO_RAD = TAU / 360.0,
                        RAD_TO_DEG = 360.0 / TAU;
double sin(double x);
double cos(double x);
double tan(double x);

float sin(float x);
float cos(float x);
float tan(float x);
} // namespace math
