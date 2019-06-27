#include "Matrix.hpp"
#include "Math.hpp"

namespace Math {
    ////////////////////////////////////
    //                                //
    //            Matrix2x2           //
    //                                //
    ////////////////////////////////////
    template <typename T> constexpr Matrix<T, 2, 2>::Matrix() : data{{1, 0}, {0, 1}} {}
    template <typename T> constexpr Matrix<T, 2, 2>::Matrix(const Matrix<T, 2, 2> &m) : data{m.data[0], m.data[1]} {}
    template <typename T>
    constexpr Matrix<T, 2, 2>::Matrix(const Vector<T, 2> &v1, const Vector<T, 2> &v2) : data{v1, v2} {}
    template <typename T> inline constexpr Vector<T, 2> Matrix<T, 2, 2>::operator[](int index) const {
        return *((Vector<T, 2> *)this + index);
    }
    ////////////////////////////////////
    //                                //
    //            Matrix3x3           //
    //                                //
    ////////////////////////////////////
    template <typename T> constexpr Matrix<T, 3, 3>::Matrix() : data{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}} {}
    template <typename T>
    constexpr Matrix<T, 3, 3>::Matrix(const Matrix<T, 3, 3> &m) : data{m.data[0], m.data[1], m.data[2]} {}
    template <typename T>
    constexpr Matrix<T, 3, 3>::Matrix(const Vector<T, 3> &v1, const Vector<T, 3> &v2, const Vector<T, 3> &v3)
        : data{v1, v2, v3} {}
    template <typename T> inline constexpr Vector<T, 3> Matrix<T, 3, 3>::operator[](int index) const {
        return *((Vector<T, 3> *)this + index);
    }
    ////////////////////////////////////
    //                                //
    //            Matrix4x4           //
    //                                //
    ////////////////////////////////////
    template <typename T>
    constexpr Matrix<T, 4, 4>::Matrix() : data{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}} {}
    template <typename T>
    constexpr Matrix<T, 4, 4>::Matrix(const Matrix<T, 4, 4> &m) : data{m.data[0], m.data[1], m.data[2], m.data[3]} {}
    template <typename T>
    constexpr Matrix<T, 4, 4>::Matrix(const Vector<T, 4> &v1, const Vector<T, 4> &v2, const Vector<T, 4> &v3,
                                      const Vector<T, 4> &v4)
        : data{v1, v2, v3, v4} {}
    template <typename T> inline constexpr Matrix<T, 4, 4> &Matrix<T, 4, 4>::operator+=(const Matrix<T, 4, 4> &m) {
        data[0] += m.data[0];
        data[1] += m.data[1];
        data[2] += m.data[2];
        data[3] += m.data[3];
        return *this;
    }
    template <typename T> inline constexpr Matrix<T, 4, 4> &Matrix<T, 4, 4>::operator-=(const Matrix<T, 4, 4> &m) {
        data[0] -= m.data[0];
        data[1] -= m.data[1];
        data[2] -= m.data[2];
        data[3] -= m.data[3];
        return *this;
    }
    template <typename T> inline constexpr Matrix<T, 4, 4> &Matrix<T, 4, 4>::operator*=(const Matrix<T, 4, 4> &m) {
        Matrix<T, 4, 4> result({data[0][0] * m.data[0][0] + data[1][0] * m.data[0][1] + data[2][0] * m.data[0][2] +
                                    data[3][0] * m.data[0][3],
                                data[0][0] * m.data[1][0] + data[1][0] * m.data[1][1] + data[2][0] * m.data[1][2] +
                                    data[3][0] * m.data[1][3],
                                data[0][0] * m.data[2][0] + data[1][0] * m.data[2][1] + data[2][0] * m.data[2][2] +
                                    data[3][0] * m.data[2][3],
                                data[0][0] * m.data[3][0] + data[1][0] * m.data[3][1] + data[2][0] * m.data[3][2] +
                                    data[3][0] * m.data[3][3]},
                               {data[0][1] * m.data[0][0] + data[1][1] * m.data[0][1] + data[2][1] * m.data[0][2] +
                                    data[3][1] * m.data[0][3],
                                data[0][1] * m.data[1][0] + data[1][1] * m.data[1][1] + data[2][1] * m.data[1][2] +
                                    data[3][1] * m.data[1][3],
                                data[0][1] * m.data[2][0] + data[1][1] * m.data[2][1] + data[2][1] * m.data[2][2] +
                                    data[3][1] * m.data[2][3],
                                data[0][1] * m.data[3][0] + data[1][1] * m.data[3][1] + data[2][1] * m.data[3][2] +
                                    data[3][1] * m.data[3][3]},
                               {data[0][2] * m.data[0][0] + data[1][2] * m.data[0][1] + data[2][2] * m.data[0][2] +
                                    data[3][2] * m.data[0][3],
                                data[0][2] * m.data[1][0] + data[1][2] * m.data[1][1] + data[2][2] * m.data[1][2] +
                                    data[3][2] * m.data[1][3],
                                data[0][2] * m.data[2][0] + data[1][2] * m.data[2][1] + data[2][2] * m.data[2][2] +
                                    data[3][2] * m.data[2][3],
                                data[0][2] * m.data[3][0] + data[1][2] * m.data[3][1] + data[2][2] * m.data[3][2] +
                                    data[3][2] * m.data[3][3]},
                               {data[0][3] * m.data[0][0] + data[1][3] * m.data[0][1] + data[2][3] * m.data[0][2] +
                                    data[3][3] * m.data[0][3],
                                data[0][3] * m.data[1][0] + data[1][3] * m.data[1][1] + data[2][3] * m.data[1][2] +
                                    data[3][3] * m.data[1][3],
                                data[0][3] * m.data[2][0] + data[1][3] * m.data[2][1] + data[2][3] * m.data[2][2] +
                                    data[3][3] * m.data[2][3],
                                data[0][3] * m.data[3][0] + data[1][3] * m.data[3][1] + data[2][3] * m.data[3][2] +
                                    data[3][3] * m.data[3][3]});
        *this = result;
        return *this;
    }
    template <typename T> inline constexpr Vector<T, 4> Matrix<T, 4, 4>::operator[](int index) const {
        return *((Vector<T, 4> *)this + index);
    }
    template <typename T> constexpr Matrix<T, 4, 4> Matrix<T, 4, 4>::ortho(T l, T r, T b, T t, T n, T f) {
        return {{(T)2 / (r - l), 0, 0, 0},
                {0, (T)2 / (t - b), 0, 0},
                {0, 0, (T)2 / (n - f), 0},
                {(l + r) / (l - r), (b + t) / (b - t), (f + n) / (n - f), 1}};
    }
    template <typename T> constexpr Matrix<T, 4, 4> Matrix<T, 4, 4>::translation(const Vector<T, 3> delta) {
        return {{1, 0, 0, delta.x}, {0, 1, 0, delta.y}, {0, 0, 1, delta.z}, {0, 0, 0, 1}};
    }
    template <typename T> constexpr Matrix<T, 4, 4> Matrix<T, 4, 4>::rotation(float angle, const Vector<T, 3> axis) {
        T c = cos(angle), s = sin(angle), omc = 1.0f - c, x = axis.x, y = axis.y, z = axis.z;
        return {{x * x * omc + c, x * y * omc - z * s, x * z * omc + y * s, 0},
                {y * x * omc + z * s, y * y * omc + c, y * z * omc - x * s, 0},
                {x * z * omc - y * s, y * z * omc + x * s, z * z * omc + c, 0},
                {0, 0, 0, 1}};
    }
    template <typename T> constexpr Matrix<T, 4, 4> Matrix<T, 4, 4>::scalar(const Vector<T, 3> factor) {
        return {{factor.x, 0, 0, 0}, {0, factor.y, 0, 0}, {0, 0, factor.z, 0}, {0, 0, 0, 1}};
    }

    template struct Matrix<float, 2, 2>;
    template struct Matrix<float, 3, 3>;
    template struct Matrix<float, 4, 4>;
} // namespace Math
