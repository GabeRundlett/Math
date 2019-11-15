#pragma once

#include "common.hpp"

#ifdef __linux__
#define INTERNAL_MATH_SQUARE_ROOT_FUNC __builtin_sqrt
#endif
#ifndef INTERNAL_MATH_SQUARE_ROOT_FUNC
#include <cmath>
#define INTERNAL_MATH_SQUARE_ROOT_FUNC ::std::sqrt
#endif

namespace math {
    template <typename T, int N> struct Vector { T data[N]; };

    template <typename T> struct Vector<T, 2> {
        union {
            T data[2];
            struct {
                T x, y;
            };
        };

        inline constexpr auto operator+(const Vector<T, 2> &v) const { return Vector<T, 2>{x + v.x, y + v.y}; }
        inline constexpr auto operator-(const Vector<T, 2> &v) const { return Vector<T, 2>{x - v.x, y - v.y}; }
        inline constexpr auto operator*(const Vector<T, 2> &v) const { return Vector<T, 2>{x * v.x, y * v.y}; }
        inline constexpr auto operator/(const Vector<T, 2> &v) const { return Vector<T, 2>{x / v.x, y / v.y}; }
        inline constexpr auto operator*(const T a) const { return Vector<T, 2>{x * a, y * a}; }
        inline constexpr auto operator/(const T a) const { return Vector<T, 2>{x / a, y / a}; }
        inline constexpr auto &operator+=(const Vector<T, 2> &v) {
            x += v.x, y += v.y;
            return *this;
        }
        inline constexpr auto &operator-=(const Vector<T, 2> &v) {
            x -= v.x, y -= v.y;
            return *this;
        }
        inline constexpr auto &operator*=(const Vector<T, 2> &v) {
            x *= v.x, y *= v.y;
            return *this;
        }
        inline constexpr auto &operator/=(const Vector<T, 2> &v) {
            x /= v.x, y /= v.y;
            return *this;
        }
        inline constexpr auto &operator*=(const T a) {
            x *= a, y *= a;
            return *this;
        }
        inline constexpr auto &operator/=(const T a) {
            x /= a, y /= a;
            return *this;
        }
        inline constexpr auto &operator[](const unsigned int index) const { return data[index]; }
        inline constexpr auto dot(const Vector<T, 2> &v) const { return x * v.x + y * v.y; }
        inline constexpr auto length() const { return static_cast<T>(INTERNAL_MATH_SQUARE_ROOT_FUNC(sq(x) + sq(y))); }
        inline constexpr auto &normalize() {
            T factor = static_cast<T>(1) / length();
            x *= factor, y *= factor;
            return *this;
        }
    };

    template <typename T> struct Vector<T, 3> {
        union {
            T data[3];
            struct {
                T x, y, z;
            };
        };
        inline constexpr auto operator+(const Vector<T, 3> &v) const { return Vector<T, 3>{x + v.x, y + v.y, z + v.z}; }
        inline constexpr auto operator-(const Vector<T, 3> &v) const { return Vector<T, 3>{x - v.x, y - v.y, z - v.z}; }
        inline constexpr auto operator*(const Vector<T, 3> &v) const { return Vector<T, 3>{x * v.x, y * v.y, z * v.z}; }
        inline constexpr auto operator/(const Vector<T, 3> &v) const { return Vector<T, 3>{x / v.x, y / v.y, z / v.z}; }
        inline constexpr auto operator*(const T a) const { return Vector<T, 3>{x * a, y * a, z * a}; }
        inline constexpr auto operator/(const T a) const { return Vector<T, 3>{x / a, y / a, z / a}; }
        inline constexpr auto operator+=(const Vector<T, 3> &v) {
            x += v.x, y += v.y, z += v.z;
            return *this;
        }
        inline constexpr auto &operator-=(const Vector<T, 3> &v) {
            x -= v.x, y -= v.y, z -= v.z;
            return *this;
        }
        inline constexpr auto &operator*=(const Vector<T, 3> &v) {
            x *= v.x, y *= v.y, z *= v.z;
            return *this;
        }
        inline constexpr auto &operator/=(const Vector<T, 3> &v) {
            x /= v.x, y /= v.y, z /= v.z;
            return *this;
        }
        inline constexpr auto &operator*=(const T a) {
            x *= a, y *= a, z *= a;
            return *this;
        }
        inline constexpr auto &operator/=(const T a) {
            x /= a, y /= a, z /= a;
            return *this;
        }
        inline constexpr auto &operator[](const unsigned int index) const { return data[index]; }
        inline constexpr auto dot(const Vector<T, 3> &v) const { return x * v.x + y * v.y + z * v.z; }
        inline constexpr auto cross(const Vector<T, 3> &v) const {
            return Vector<T, 3>{y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
        }
        inline constexpr auto length() const { return static_cast<T>(INTERNAL_MATH_SQUARE_ROOT_FUNC(sq(x) + sq(y) + sq(z))); }
        inline constexpr auto &normalize() {
            T factor = static_cast<T>(1) / length();
            x *= factor, y *= factor, z *= factor;
            return *this;
        }
    };

    template <typename T> struct Vector<T, 4> {
        union {
            T data[4];
            struct {
                T x, y, z, w;
            };
        };
        inline constexpr auto operator+(const Vector<T, 4> &v) const {
            return Vector<T, 4>{x + v.x, y + v.y, z + v.z, w + v.w};
        }
        inline constexpr auto operator-(const Vector<T, 4> &v) const {
            return Vector<T, 4>{x - v.x, y - v.y, z - v.z, w - v.w};
        }
        inline constexpr auto operator*(const Vector<T, 4> &v) const {
            return Vector<T, 4>{x * v.x, y * v.y, z * v.z, w * v.w};
        }
        inline constexpr auto operator/(const Vector<T, 4> &v) const {
            return Vector<T, 4>{x / v.x, y / v.y, z / v.z, w / v.w};
        }
        inline constexpr auto operator*(const T v) const { return Vector<T, 4>{x * v, y * v, z * v, w * v}; }
        inline constexpr auto operator/(const T v) const { return Vector<T, 4>{x / v, y / v, z / v, w / v}; }
        inline constexpr auto &operator+=(const Vector<T, 4> &v) {
            x += v.x, y += v.y, z += v.z, w += v.w;
            return *this;
        }
        inline constexpr auto &operator-=(const Vector<T, 4> &v) {
            x -= v.x, y -= v.y, z -= v.z, w -= v.w;
            return *this;
        }
        inline constexpr auto &operator*=(const Vector<T, 4> &v) {
            x *= v.x, y *= v.y, z *= v.z, w *= v.w;
            return *this;
        }
        inline constexpr auto &operator/=(const Vector<T, 4> &v) {
            x /= v.x, y /= v.y, z /= v.z, w /= v.w;
            return *this;
        }
        inline constexpr auto &operator*=(const T a) {
            x *= a, y *= a, z *= a, w *= a;
            return *this;
        }
        inline constexpr auto &operator/=(const T a) {
            x /= a, y /= a, z /= a, w /= a;
            return *this;
        }
        inline constexpr auto &operator[](const unsigned int index) const { return data[index]; }
        inline constexpr auto dot(const Vector<T, 4> &v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
        inline constexpr auto length() const {
            return static_cast<T>(INTERNAL_MATH_SQUARE_ROOT_FUNC(sq(x) + sq(y) + sq(z) + sq(w)));
        }
        inline constexpr auto &normalize() {
            T factor = static_cast<T>(1) / length();
            x *= factor, y *= factor, z *= factor, w *= factor;
            return *this;
        }
    };

    template <> struct Vector<unsigned char, 4> {
        unsigned char r, g, b, a;
        constexpr Vector(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}
        constexpr Vector(unsigned int hex)
            : r(static_cast<unsigned char>(hex >> 24)), g(static_cast<unsigned char>(hex >> 16)),
              b(static_cast<unsigned char>(hex >> 8)), a(static_cast<unsigned char>(hex >> 0)) {}
    };
} // namespace math
