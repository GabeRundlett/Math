#pragma once

namespace math {
template <typename T, int N> struct Complex;

template <typename T> struct Complex<T, 2> {
    T r, i;

    Complex<T, 2> &operator+=(const Complex<T, 2> &c);
    Complex<T, 2> &operator-=(const Complex<T, 2> &c);
    Complex<T, 2> &operator*=(const Complex<T, 2> &c);
    Complex<T, 2> &operator/=(const Complex<T, 2> &c);
    Complex<T, 2> operator+(const Complex<T, 2> &c);
    Complex<T, 2> operator-(const Complex<T, 2> &c);
    Complex<T, 2> operator*(const Complex<T, 2> &c);
    Complex<T, 2> operator/(const Complex<T, 2> &c);
    T &operator[](int index) const;
};
template <typename T> struct Complex<T, 4> {
    T r, i, j, k;

    Complex<T, 4> &operator+=(const Complex<T, 4> &c);
    Complex<T, 4> &operator-=(const Complex<T, 4> &c);
    Complex<T, 4> &operator*=(const Complex<T, 4> &c);
    Complex<T, 4> &operator/=(const Complex<T, 4> &c);
    Complex<T, 4> operator+(const Complex<T, 4> &c);
    Complex<T, 4> operator-(const Complex<T, 4> &c);
    Complex<T, 4> operator*(const Complex<T, 4> &c);
    Complex<T, 4> operator/(const Complex<T, 4> &c);
    T &operator[](int index) const;
};
} // namespace math
