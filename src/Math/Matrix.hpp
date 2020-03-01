#pragma once

#include "Vector.hpp"

namespace Math {
    template <typename T, int Rows, int Cols> struct Matrix;

    template <typename T> struct Matrix<T, 2, 2> {
        Vector<T, 2> data[2];

        constexpr Matrix() : data{{1, 0}, {0, 1}} {}
        constexpr Matrix(const Matrix<T, 2, 2> &m) : data{m.data[0], m.data[1]} {}
        constexpr Matrix(const Vector<T, 2> &v1, const Vector<T, 2> &v2) : data{v1, v2} {}

        inline constexpr auto &operator[](const unsigned int index) const { return data[index]; }
    };

    template <typename T> struct Matrix<T, 3, 3> {
        Vector<T, 3> data[3];

        constexpr Matrix() : data{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}} {}
        constexpr Matrix(const Matrix<T, 3, 3> &m) : data{m.data[0], m.data[1], m.data[2]} {}
        constexpr Matrix(const Vector<T, 3> &v1, const Vector<T, 3> &v2, const Vector<T, 3> &v3) : data{v1, v2, v3} {}

        inline constexpr auto &operator*=(const Matrix<T, 3, 3> &m) {
            Matrix<T, 3, 3> result({data[0][0] * m.data[0][0] + data[1][0] * m.data[0][1] + data[2][0] * m.data[0][2],
                                    data[0][0] * m.data[1][0] + data[1][0] * m.data[1][1] + data[2][0] * m.data[1][2],
                                    data[0][0] * m.data[2][0] + data[1][0] * m.data[2][1] + data[2][0] * m.data[2][2]},
                                   {data[0][1] * m.data[0][0] + data[1][1] * m.data[0][1] + data[2][1] * m.data[0][2],
                                    data[0][1] * m.data[1][0] + data[1][1] * m.data[1][1] + data[2][1] * m.data[1][2],
                                    data[0][1] * m.data[2][0] + data[1][1] * m.data[2][1] + data[2][1] * m.data[2][2]},
                                   {data[0][2] * m.data[0][0] + data[1][2] * m.data[0][1] + data[2][2] * m.data[0][2],
                                    data[0][2] * m.data[1][0] + data[1][2] * m.data[1][1] + data[2][2] * m.data[1][2],
                                    data[0][2] * m.data[2][0] + data[1][2] * m.data[2][1] + data[2][2] * m.data[2][2]});
            *this = result;
            return *this;
        }

        static inline constexpr auto rotX(float angle) {
            T c = cos(angle), s = sin(angle);
            return Matrix<T, 3, 3>{
                {1, 0, 0},
                {0, c, -s},
                {0, s, c},
            };
        }

        static inline constexpr auto rotY(float angle) {
            T c = cos(angle), s = sin(angle);
            return Matrix<T, 3, 3>{
                {c, 0, -s},
                {0, 1, 0},
                {s, 0, c},
            };
        }

        static inline constexpr auto rotZ(float angle) {
            T c = cos(angle), s = sin(angle);
            return Matrix<T, 3, 3>{
                {c, -s, 0},
                {s, c, 0},
                {0, 0, 1},
            };
        }

        inline constexpr auto &operator[](const unsigned int index) const { return data[index]; }
    };

    template <typename T> struct Matrix<T, 4, 4> {
        Vector<T, 4> data[4];

        constexpr Matrix(T val) : data{{val, 0, 0, 0}, {0, val, 0, 0}, {0, 0, val, 0}, {0, 0, 0, val}} {}
        constexpr Matrix(const Matrix<T, 4, 4> &m) : data{m.data[0], m.data[1], m.data[2], m.data[3]} {}
        constexpr Matrix(const Vector<T, 4> &v1, const Vector<T, 4> &v2, const Vector<T, 4> &v3, const Vector<T, 4> &v4)
            : data{v1, v2, v3, v4} {}

        inline constexpr auto &operator+=(const Matrix<T, 4, 4> &m) {
            data[0] += m.data[0], data[1] += m.data[1], data[2] += m.data[2], data[3] += m.data[3];
            return *this;
        }
        inline constexpr auto &operator-=(const Matrix<T, 4, 4> &m) {
            data[0] -= m.data[0], data[1] -= m.data[1], data[2] -= m.data[2], data[3] -= m.data[3];
            return *this;
        }

        inline constexpr auto &operator*=(const Matrix<T, 4, 4> &m) {
            const T m11 = data[0][0] * m.data[0][0] + data[1][0] * m.data[0][1] + data[2][0] * m.data[0][2] +
                          data[3][0] * m.data[0][3],
                    m12 = data[0][0] * m.data[1][0] + data[1][0] * m.data[1][1] + data[2][0] * m.data[1][2] +
                          data[3][0] * m.data[1][3],
                    m13 = data[0][0] * m.data[2][0] + data[1][0] * m.data[2][1] + data[2][0] * m.data[2][2] +
                          data[3][0] * m.data[2][3],
                    m14 = data[0][0] * m.data[3][0] + data[1][0] * m.data[3][1] + data[2][0] * m.data[3][2] +
                          data[3][0] * m.data[3][3],
                    m21 = data[0][1] * m.data[0][0] + data[1][1] * m.data[0][1] + data[2][1] * m.data[0][2] +
                          data[3][1] * m.data[0][3],
                    m22 = data[0][1] * m.data[1][0] + data[1][1] * m.data[1][1] + data[2][1] * m.data[1][2] +
                          data[3][1] * m.data[1][3],
                    m23 = data[0][1] * m.data[2][0] + data[1][1] * m.data[2][1] + data[2][1] * m.data[2][2] +
                          data[3][1] * m.data[2][3],
                    m24 = data[0][1] * m.data[3][0] + data[1][1] * m.data[3][1] + data[2][1] * m.data[3][2] +
                          data[3][1] * m.data[3][3],
                    m31 = data[0][2] * m.data[0][0] + data[1][2] * m.data[0][1] + data[2][2] * m.data[0][2] +
                          data[3][2] * m.data[0][3],
                    m32 = data[0][2] * m.data[1][0] + data[1][2] * m.data[1][1] + data[2][2] * m.data[1][2] +
                          data[3][2] * m.data[1][3],
                    m33 = data[0][2] * m.data[2][0] + data[1][2] * m.data[2][1] + data[2][2] * m.data[2][2] +
                          data[3][2] * m.data[2][3],
                    m34 = data[0][2] * m.data[3][0] + data[1][2] * m.data[3][1] + data[2][2] * m.data[3][2] +
                          data[3][2] * m.data[3][3],
                    m41 = data[0][3] * m.data[0][0] + data[1][3] * m.data[0][1] + data[2][3] * m.data[0][2] +
                          data[3][3] * m.data[0][3],
                    m42 = data[0][3] * m.data[1][0] + data[1][3] * m.data[1][1] + data[2][3] * m.data[1][2] +
                          data[3][3] * m.data[1][3],
                    m43 = data[0][3] * m.data[2][0] + data[1][3] * m.data[2][1] + data[2][3] * m.data[2][2] +
                          data[3][3] * m.data[2][3],
                    m44 = data[0][3] * m.data[3][0] + data[1][3] * m.data[3][1] + data[2][3] * m.data[3][2] +
                          data[3][3] * m.data[3][3];

            Matrix<T, 4, 4> result{
                {m11, m21, m31, m41},
                {m12, m22, m32, m42},
                {m13, m23, m33, m43},
                {m14, m24, m34, m44},
            };
            *this = result;
            return *this;
        }
        inline constexpr auto &operator[](const unsigned int index) const { return data[index]; }

        static inline constexpr auto ortho(T l, T r, T b, T t, T n, T f) {
            return Matrix<T, 4, 4>{{(T)2 / (r - l), 0, 0, 0},
                                    {0, (T)2 / (t - b), 0, 0},
                                    {0, 0, (T)2 / (n - f), 0},
                                    {(l + r) / (l - r), (b + t) / (b - t), (f + n) / (n - f), 1}};
        }
        static inline constexpr auto perspective(T fov, T aspect, T near, T far) {
            const T q = (T)1.0 / std::tan(0.5 * fov), a = q * aspect, b = (near + far) / (near - far), c = near * far * 2 / (near - far);
            return Matrix<T, 4, 4>{
                {q, 0, 0, 0},
                {0, a, 0, 0},
                {0, 0, b, -1},
                {0, 0, c, 0},
            };
        }
        static inline constexpr auto identity() {
            return Matrix<T, 4, 4>{
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
            };
        }
        static inline constexpr auto translation(const Vector<T, 3> delta) {
            return Matrix<T, 4, 4>{
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {delta.x, delta.y, delta.z, 1},
            };
        }
        static inline constexpr auto rotation(float angle, const Vector<T, 3> axis) {
            const T c = std::cos(angle), s = std::sin(angle), o = (T)1 - c, x = axis.x, y = axis.y, z = axis.z;
            const T xo = x * o, yo = y * o, zo = z * o, xs = x * s, ys = y * s, zs = z * s;
            return Matrix<T, 4, 4>{
                {xo * x + c, yo * x - zs, zo * x + ys, 0},
                {xo * y + zs, yo * y + c, zo * y - xs, 0},
                {xo * z - ys, yo * z + xs, zo * z + c, 0},
                {0, 0, 0, 1},
            };
        }
        static inline constexpr auto rotX(float angle) {
            const T c = std::cos(angle), s = std::sin(angle);
            return Matrix<T, 4, 4>{
                {1, 0, 0, 0},
                {0, c, -s, 0},
                {0, s, c, 0},
                {0, 0, 0, 1},
            };
        }
        static inline constexpr auto rotY(float angle) {
            const T c = std::cos(angle), s = std::sin(angle);
            return Matrix<T, 4, 4>{
                {c, 0, -s, 0},
                {0, 1, 0, 0},
                {s, 0, c, 0},
                {0, 0, 0, 1},
            };
        }
        static inline constexpr auto rotZ(float angle) {
            const T c = std::cos(angle), s = std::sin(angle);
            return Matrix<T, 4, 4>{
                {c, -s, 0, 0},
                {s, c, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
            };
        }
        static inline constexpr auto scalar(const Vector<T, 3> factor) {
            return Matrix<T, 4, 4>{
                {factor.x, 0, 0, 0},
                {0, factor.y, 0, 0},
                {0, 0, factor.z, 0},
                {0, 0, 0, 1},
            };
        }
    };
} // namespace Math
