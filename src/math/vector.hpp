#pragma once

namespace math {
    template <typename T, int N> struct Vector;

    template <typename T> struct Vector<T, 2> {
        T x, y;

        constexpr static float length(const Vector<T, 2> &v);
        constexpr static Vector<T, 2> normalize(const Vector<T, 2> &v);

        constexpr Vector<T, 2> &operator+=(const Vector<T, 2> &v);
        constexpr Vector<T, 2> &operator-=(const Vector<T, 2> &v);
        constexpr Vector<T, 2> &operator*=(const T fac);
        constexpr Vector<T, 2> &operator/=(const T fac);
        constexpr Vector<T, 2> operator+(const Vector<T, 2> &v) const;
        constexpr Vector<T, 2> operator-(const Vector<T, 2> &v) const;
        constexpr Vector<T, 2> operator*(const T fac) const;
        constexpr Vector<T, 2> operator/(const T fac) const;
        constexpr T &operator[](int index) const;
    };

    template <typename T> struct Vector<T, 3> {
        T x, y, z;

        constexpr Vector<T, 3> &operator+=(const Vector<T, 3> &v);
        constexpr Vector<T, 3> &operator-=(const Vector<T, 3> &v);
        constexpr Vector<T, 3> &operator*=(const T fac);
        constexpr Vector<T, 3> &operator/=(const T fac);
        constexpr Vector<T, 3> operator+(const Vector<T, 3> &v) const;
        constexpr Vector<T, 3> operator-(const Vector<T, 3> &v) const;
        constexpr Vector<T, 3> operator*(const T fac) const;
        constexpr Vector<T, 3> operator/(const T fac) const;
        constexpr T &operator[](int index) const;
    };

    template <typename T> struct Vector<T, 4> {
        T x, y, z, w;

        constexpr Vector<T, 4> &operator+=(const Vector<T, 4> &v);
        constexpr Vector<T, 4> &operator-=(const Vector<T, 4> &v);
        constexpr Vector<T, 4> &operator*=(const T fac);
        constexpr Vector<T, 4> &operator/=(const T fac);
        constexpr Vector<T, 4> operator+(const Vector<T, 4> &v) const;
        constexpr Vector<T, 4> operator-(const Vector<T, 4> &v) const;
        constexpr Vector<T, 4> operator*(const T fac) const;
        constexpr Vector<T, 4> operator/(const T fac) const;
        constexpr T &operator[](int index) const;
    };

    template <> struct Vector<unsigned char, 4> {
        unsigned char r, g, b, a;
        constexpr Vector(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}
        constexpr Vector(unsigned int hex) : r(char(hex >> 24)), g(char(hex >> 16)), b(char(hex >> 8)), a(char(hex >> 0)) {}
    };
} // namespace math
