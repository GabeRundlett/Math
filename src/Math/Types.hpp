#pragma once

#include "Complex.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

#ifndef _CONFIG_MATH_NO_TYPEDEF
namespace Math {
////////////////////////////////////
//                                //
//             Vector             //
//                                //
////////////////////////////////////
typedef Vector<float, 2> vec2;
typedef Vector<float, 3> vec3;
typedef Vector<float, 4> vec4;

typedef Vector<double, 2> dvec2;
typedef Vector<double, 3> dvec3;
typedef Vector<double, 4> dvec4;

typedef Vector<int, 2> ivec2;
typedef Vector<int, 3> ivec3;
typedef Vector<int, 4> ivec4;

typedef Vector<unsigned char, 4> color;
////////////////////////////////////
//                                //
//             Matrix             //
//                                //
////////////////////////////////////
typedef Matrix<float, 2, 2> mat2;
typedef Matrix<float, 3, 3> mat3;
typedef Matrix<float, 4, 4> mat4;
////////////////////////////////////
//                                //
//             Complex            //
//                                //
////////////////////////////////////
typedef Complex<float, 2> comp;
typedef Complex<float, 4> quat;
} // namespace Math
#endif
