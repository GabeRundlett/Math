#pragma once

#include "complex.hpp"
#include "matrix.hpp"
#include "vector.hpp"

#ifndef _CONFIG_MATH_NO_TYPEDEF
namespace math {
////////////////////////////////////
//                                //
//             Vector             //
//                                //
////////////////////////////////////
typedef Vector<float, 2> Vec2;
typedef Vector<float, 3> Vec3;
typedef Vector<float, 4> Vec4;

typedef Vector<double, 2> dVec2;
typedef Vector<double, 3> dVec3;
typedef Vector<double, 4> dVec4;

typedef Vector<int, 2> iVec2;
typedef Vector<int, 3> iVec3;
typedef Vector<int, 4> iVec4;

typedef Vector<unsigned char, 4> Color;
////////////////////////////////////
//                                //
//             Matrix             //
//                                //
////////////////////////////////////
typedef Matrix<float, 2, 2> Mat2;
typedef Matrix<float, 3, 3> Mat3;
typedef Matrix<float, 4, 4> Mat4;
////////////////////////////////////
//                                //
//             Complex            //
//                                //
////////////////////////////////////
typedef Complex<float, 2> Comp;
typedef Complex<float, 4> Quat;
} // namespace math
#endif
