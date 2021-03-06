#pragma once

#include "Complex.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

#ifndef CONFIG_MATH_NO_TYPEDEF
namespace Math {
    ////////////////////////////////////
    //                                //
    //             Vector             //
    //                                //
    ////////////////////////////////////
    typedef Vector<float, 2> Vec2;
    typedef Vector<float, 3> Vec3;
    typedef Vector<float, 4> Vec4;

    typedef Vector<double, 2> Vec2d;
    typedef Vector<double, 3> Vec3d;
    typedef Vector<double, 4> Vec4d;

    typedef Vector<int, 2> Vec2i;
    typedef Vector<int, 3> Vec3i;
    typedef Vector<int, 4> Vec4i;

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
} // namespace Math
#endif
