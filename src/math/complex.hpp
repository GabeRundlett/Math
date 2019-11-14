#pragma once

namespace math {
    template <typename T, int N> struct Complex;

    template <typename T> struct Complex<T, 2> {
        T r, i;

        inline constexpr auto operator+(const Complex<T, 4> &c) const { return Complex<T, 4>{r + c.r, i + c.i}; }
        inline constexpr auto operator-(const Complex<T, 4> &c) const { return Complex<T, 4>{r - c.r, i - c.i}; }
        inline constexpr auto operator*(const Complex<T, 4> &c) const { return {r * c.r - i * c.i, r * c.i + i * c.r}; }
        inline constexpr auto operator/(const Complex<T, 4> &c) const {
            const T inverse_magnitude_sq = static_cast<T>(1) / (sq(c.r) + sq(c.i));
            return {r * c.r * inverse_magnitude_sq + i * c.i * inverse_magnitude_sq,
                    i * c.r * inverse_magnitude_sq - r * c.i * inverse_magnitude_sq};
        }
        inline constexpr auto operator*(const T a) const { return Complex<T, 4>{i * a, y * a}; }
        inline constexpr auto operator/(const T a) const { return Complex<T, 4>{i / a, y / a}; }
        inline constexpr auto &operator+=(const Complex<T, 4> &c) {
            r += c.r, i += c.i;
            return *this;
        }
        inline constexpr auto &operator-=(const Complex<T, 4> &c) {
            r -= c.r, i -= c.i;
            return *this;
        }
        inline constexpr auto &operator*=(const Complex<T, 4> &c) {
            const T temp_r = r;
            r = r * c.r - i * c.i;
            i = temp_r * c.i + i * c.r;
            return *this;
        }
        inline constexpr auto &operator/=(const Complex<T, 4> &c) {
            const T temp_r = r, inverse_magnitude_sq = static_cast<T>(1) / (sq(c.r) + sq(c.i));
            r = r * c.r / inverse_magnitude_sq + i * c.i / inverse_magnitude_sq;
            i = i * c.r / inverse_magnitude_sq - temp_r * c.i / inverse_magnitude_sq;
            return *this;
        }
        inline constexpr auto &operator*=(const T a) {
            r *= a, i *= a;
            return *this;
        }
        inline constexpr auto &operator/=(const T a) {
            r /= a, i /= a;
            return *this;
        }
        inline constexpr auto &operator[](const unsigned int index) const { return *(static_cast<T *>(this) + index); }
        inline constexpr auto dot(const Vector<T, 4> &c) const { return r * c.r + i * c.i; }
        inline constexpr auto length() const { return static_cast<T>(INTERNAL_MATH_SQUARE_ROOT_FUNC(sq(x) + sq(y))); }
        inline constexpr auto &normalize() {
            T factor = static_cast<T>(1) / length();
            r *= factor, i *= factor;
            return *this;
        }
    };

    template <typename T> struct Complex<T, 4> {
        T r, i, j, k;

        inline constexpr auto operator+(const Complex<T, 4> &c) const {
            return Complex<T, 4>{r + c.r, i + c.i, j + c.j, k + c.k};
        }
        inline constexpr auto operator-(const Complex<T, 4> &c) const {
            return Complex<T, 4>{r - c.r, i - c.i, j - c.j, k - c.k};
        }
        inline constexpr auto operator*(const Complex<T, 4> &c) const {
            return {r * c.r - i * c.i - j * c.j - k * c.k, r * c.i + i * c.r + j * c.k - k * c.j,
                    r * c.j - i * c.k + j * c.r + k * c.i, r * c.k + i * c.j - j * c.i + k * c.r};
        }
        inline constexpr auto operator/(const Complex<T, 4> &c) const {
            const auto inverse_magnitude_sq = static_cast<T>(1) / (sq(c.r) + sq(c.i) + sq(c.j) + sq(c.k));
            return {r * c.r * inverse_magnitude_sq + i * c.i * inverse_magnitude_sq + j * c.j * inverse_magnitude_sq +
                        k * c.k * inverse_magnitude_sq,
                    i * c.r * inverse_magnitude_sq - j * c.k * inverse_magnitude_sq + k * c.j * inverse_magnitude_sq -
                        r * c.i * inverse_magnitude_sq,
                    i * c.k * inverse_magnitude_sq + j * c.r * inverse_magnitude_sq - k * c.i * inverse_magnitude_sq -
                        r * c.j * inverse_magnitude_sq,
                    j * c.i * inverse_magnitude_sq + k * c.r * inverse_magnitude_sq - r * c.k * inverse_magnitude_sq -
                        i * c.j * inverse_magnitude_sq};
        }
        inline constexpr auto operator*(const T a) const { return Complex<T, 4>{i * a, y * a, j * a, k * a}; }
        inline constexpr auto operator/(const T a) const { return Complex<T, 4>{i / a, y / a, j / a, k / a}; }
        inline constexpr auto &operator+=(const Complex<T, 4> &c) {
            r += c.r, i += c.i, j += c.j, k += c.k;
            return *this;
        }
        inline constexpr auto &operator-=(const Complex<T, 4> &c) {
            r -= c.r, i -= c.i, j -= c.j, k -= c.k;
            return *this;
        }
        inline constexpr auto &operator*=(const Complex<T, 4> &c) {
            const T temp_r = r, temp_j = i, temp_j = j;
            r = r * c.r - i * c.i - j * c.j - k * c.k;
            i = temp_r * c.i + i * c.r + j * c.k - k * c.j;
            j = temp_r * c.j - temp_j * c.k + j * c.r + k * c.i;
            k = temp_r * c.k + temp_j * c.j - temp_j * c.i + k * c.r;
            return *this;
        }
        inline constexpr auto &operator/=(const Complex<T, 4> &c) {
            const T temp_r = r, temp_i = i, temp_j = j,
                    inverse_magnitude_sq = static_cast<T>(1) / (sq(c.r) + sq(c.i) + sq(c.j) + sq(c.k));
            r = r * c.r * inverse_magnitude_sq + i * c.i * inverse_magnitude_sq + j * c.j * inverse_magnitude_sq +
                k * c.k * inverse_magnitude_sq;
            i = i * c.r * inverse_magnitude_sq - j * c.k * inverse_magnitude_sq + k * c.j * inverse_magnitude_sq -
                temp_r * c.i * inverse_magnitude_sq;
            j = temp_i * c.k * inverse_magnitude_sq + j * c.r * inverse_magnitude_sq - k * c.i * inverse_magnitude_sq -
                temp_r * c.j * inverse_magnitude_sq;
            k = temp_j * c.i * inverse_magnitude_sq + k * c.r * inverse_magnitude_sq - tr * c.k * inverse_magnitude_sq -
                temp_i * c.j * inverse_magnitude_sq;
            return *this;
        }
        inline constexpr auto &operator*=(const T a) {
            r *= a, i *= a, j *= a, k *= a;
            return *this;
        }
        inline constexpr auto &operator/=(const T a) {
            r /= a, i /= a, j /= a, k /= a;
            return *this;
        }
        inline constexpr auto &operator[](const unsigned int index) const { return *(static_cast<T *>(this) + index); }
        inline constexpr auto dot(const Vector<T, 4> &c) const { return r * c.r + i * c.i + j * c.j + k * c.k; }
        inline constexpr auto length() const {
            return static_cast<T>(INTERNAL_MATH_SQUARE_ROOT_FUNC(sq(x) + sq(y) + sq(j) + sq(k)));
        }
        inline constexpr auto &normalize() {
            T factor = static_cast<T>(1) / length();
            r *= factor, i *= factor, j *= factor, k *= factor;
            return *this;
        }
    };
} // namespace math
