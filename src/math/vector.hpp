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

#pragma once

#include "math.hpp"

#ifdef __linux__
#define SQUARE_ROOT_FUNC __builtin_sqrt
#endif
#ifndef SQUARE_ROOT_FUNC
#include <cmath>
#define SQUARE_ROOT_FUNC ::std::sqrt
#endif

namespace math {
    template <typename T, int N> struct Vector;

    template <typename T> struct Vector<T, 2> {
        T x, y;

        inline constexpr auto operator+(const Vector<T, 2> &v) { return Vector<T, 2>{x + v.x, y + v.y}; }
        inline constexpr auto operator-(const Vector<T, 2> &v) { return Vector<T, 2>{x - v.x, y - v.y}; }
        inline constexpr auto operator*(const Vector<T, 2> &v) { return Vector<T, 2>{x * v.x, y * v.y}; }
        inline constexpr auto operator/(const Vector<T, 2> &v) { return Vector<T, 2>{x / v.x, y / v.y}; }
        inline constexpr auto operator*(const T v) { return Vector<T, 2>{x * v, y * v}; }
        inline constexpr auto operator/(const T v) { return Vector<T, 2>{x / v, y / v}; }
        inline constexpr auto operator+=(const Vector<T, 2> &v) {
            x += v.x, y += v.y;
            return *this;
        }
        inline constexpr auto operator-=(const Vector<T, 2> &v) {
            x -= v.x, y -= v.y;
            return *this;
        }
        inline constexpr auto operator*=(const Vector<T, 2> &v) {
            x *= v.x, y *= v.y;
            return *this;
        }
        inline constexpr auto operator/=(const Vector<T, 2> &v) {
            x /= v.x, y /= v.y;
            return *this;
        }
        inline constexpr auto operator*=(const T v) {
            x *= v, y *= v;
            return *this;
        }
        inline constexpr auto operator/=(const T v) {
            x /= v, y /= v;
            return *this;
        }
        inline constexpr auto operator[](const unsigned int i) { return *(reinterpret_cast<T *>(this) + i); }
        inline constexpr auto dot(const Vector<T, 2> &v) { return x * v.x + y * v.y; }
        inline constexpr auto length() { return static_cast<T>(SQUARE_ROOT_FUNC(sq(x) + sq(y))); }
        inline constexpr auto normalize() {
            T factor = static_cast<T>(1) / length();
            x *= factor, y *= factor;
            return *this;
        }
    };
    template <typename T> struct Vector<T, 3> {
        T x, y, z;

        inline constexpr auto operator+(const Vector<T, 3> &v) { return Vector<T, 3>{x + v.x, y + v.y, z + v.z}; }
        inline constexpr auto operator-(const Vector<T, 3> &v) { return Vector<T, 3>{x - v.x, y - v.y, z - v.z}; }
        inline constexpr auto operator*(const Vector<T, 3> &v) { return Vector<T, 3>{x * v.x, y * v.y, z * v.z}; }
        inline constexpr auto operator/(const Vector<T, 3> &v) { return Vector<T, 3>{x / v.x, y / v.y, z / v.z}; }
        inline constexpr auto operator*(const T v) { return Vector<T, 3>{x * v, y * v, z * v}; }
        inline constexpr auto operator/(const T v) { return Vector<T, 3>{x / v, y / v, z / v}; }
        inline constexpr auto operator+=(const Vector<T, 3> &v) {
            x += v.x, y += v.y, z += v.z;
            return *this;
        }
        inline constexpr auto operator-=(const Vector<T, 3> &v) {
            x -= v.x, y -= v.y, z -= v.z;
            return *this;
        }
        inline constexpr auto operator*=(const Vector<T, 3> &v) {
            x *= v.x, y *= v.y, z *= v.z;
            return *this;
        }
        inline constexpr auto operator/=(const Vector<T, 3> &v) {
            x /= v.x, y /= v.y, z /= v.z;
            return *this;
        }
        inline constexpr auto operator*=(const T v) {
            x *= v, y *= v, z *= v;
            return *this;
        }
        inline constexpr auto operator/=(const T v) {
            x /= v, y /= v, z /= v;
            return *this;
        }
        inline constexpr auto operator[](const unsigned int i) { return *(reinterpret_cast<T *>(this) + i); }
        inline constexpr auto dot(const Vector<T, 3> &v) { return x * v.x + y * v.y + z * v.z; }
        inline constexpr auto length() { return static_cast<T>(SQUARE_ROOT_FUNC(sq(x) + sq(y) + sq(z))); }
        inline constexpr auto normalize() {
            T factor = static_cast<T>(1) / length();
            x *= factor, y *= factor, z *= factor;
            return *this;
        }
    };
    template <typename T> struct Vector<T, 4> {
        T x, y, z, w;

        inline constexpr auto operator+(const Vector<T, 4> &v) { return Vector<T, 4>{x + v.x, y + v.y, z + v.z, w + v.w}; }
        inline constexpr auto operator-(const Vector<T, 4> &v) { return Vector<T, 4>{x - v.x, y - v.y, z - v.z, w - v.w}; }
        inline constexpr auto operator*(const Vector<T, 4> &v) { return Vector<T, 4>{x * v.x, y * v.y, z * v.z, w * v.w}; }
        inline constexpr auto operator/(const Vector<T, 4> &v) { return Vector<T, 4>{x / v.x, y / v.y, z / v.z, w / v.w}; }
        inline constexpr auto operator*(const T v) { return Vector<T, 4>{x * v, y * v, z * v, w * v}; }
        inline constexpr auto operator/(const T v) { return Vector<T, 4>{x / v, y / v, z / v, w / v}; }
        inline constexpr auto operator+=(const Vector<T, 4> &v) {
            x += v.x, y += v.y, z += v.z, w += v.w;
            return *this;
        }
        inline constexpr auto operator-=(const Vector<T, 4> &v) {
            x -= v.x, y -= v.y, z -= v.z, w -= v.w;
            return *this;
        }
        inline constexpr auto operator*=(const Vector<T, 4> &v) {
            x *= v.x, y *= v.y, z *= v.z, w *= v.w;
            return *this;
        }
        inline constexpr auto operator/=(const Vector<T, 4> &v) {
            x /= v.x, y /= v.y, z /= v.z, w /= v.w;
            return *this;
        }
        inline constexpr auto operator*=(const T v) {
            x *= v, y *= v, z *= v, w *= v;
            return *this;
        }
        inline constexpr auto operator/=(const T v) {
            x /= v, y /= v, z /= v, w /= v;
            return *this;
        }
        inline constexpr auto operator[](const unsigned int i) { return *(reinterpret_cast<T *>(this) + i); }
        inline constexpr auto dot(const Vector<T, 4> &v) { return x * v.x + y * v.y + z * v.z + w * v.w; }
        inline constexpr auto length() { return static_cast<T>(SQUARE_ROOT_FUNC(sq(x) + sq(y) + sq(z) + sq(w))); }
        inline constexpr auto normalize() {
            T factor = static_cast<T>(1) / length();
            x *= factor, y *= factor, z *= factor, w *= factor;
            return *this;
        }
    };
} // namespace math
