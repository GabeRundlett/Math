#include "complex.hpp"

#define SQ(x) (x * x)

namespace math {
////////////////////////////////////
//                                //
//            Complex2            //
//                                //
////////////////////////////////////
template <typename T> inline Complex<T, 2> &Complex<T, 2>::operator+=(const Complex<T, 2> &c) {
    r += c.r;
    i += c.i;
    return *this;
}
template <typename T> inline Complex<T, 2> &Complex<T, 2>::operator-=(const Complex<T, 2> &c) {
    r -= c.r;
    i -= c.i;
    return *this;
}
template <typename T> inline Complex<T, 2> &Complex<T, 2>::operator*=(const Complex<T, 2> &c) {
    const T tr = r;
    r = r * c.r - i * c.i;
    i = tr * c.i + i * c.r;
    return *this;
}
template <typename T> inline Complex<T, 2> &Complex<T, 2>::operator/=(const Complex<T, 2> &c) {
    const T tr = r, mag2 = SQ(c.r) + SQ(c.i);
    r = r * c.r / mag2 + i * c.i / mag2;
    i = i * c.r / mag2 - tr * c.i / mag2;
    return *this;
}
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator+(const Complex<T, 2> &c) { return {r + c.r, i + c.i}; }
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator-(const Complex<T, 2> &c) { return {r - c.r, i - c.i}; }
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator*(const Complex<T, 2> &c) {
    return {r * c.r - i * c.i, r * c.i + i * c.r};
}
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator/(const Complex<T, 2> &c) {
    const T mag2 = SQ(c.r) + SQ(c.i);
    return {r * c.r / mag2 + i * c.i / mag2, i * c.r / mag2 - r * c.i / mag2};
}
template <typename T> T &Complex<T, 2>::operator[](int index) const { return *((T *)this + index); }
////////////////////////////////////
//                                //
//            Complex4            //
//                                //
////////////////////////////////////
template <typename T> inline Complex<T, 4> &Complex<T, 4>::operator+=(const Complex<T, 4> &c) {
    r += c.r;
    i += c.i;
    j += c.j;
    k += c.k;
    return *this;
}
template <typename T> inline Complex<T, 4> &Complex<T, 4>::operator-=(const Complex<T, 4> &c) {
    r -= c.r;
    i -= c.i;
    j -= c.j;
    k -= c.k;
    return *this;
}
template <typename T> inline Complex<T, 4> &Complex<T, 4>::operator*=(const Complex<T, 4> &c) {
    const T tr = r, ti = i, tj = j;
    r = r * c.r - i * c.i - j * c.j - k * c.k;
    i = tr * c.i + i * c.r + j * c.k - k * c.j;
    j = tr * c.j - ti * c.k + j * c.r + k * c.i;
    k = tr * c.k + ti * c.j - tj * c.i + k * c.r;
    return *this;
}
template <typename T> inline Complex<T, 4> &Complex<T, 4>::operator/=(const Complex<T, 4> &c) {
    const T tr = r, ti = i, tj = j, mag2 = SQ(c.r) + SQ(c.i) + SQ(c.j) + SQ(c.k);
    r = r * c.r / mag2 + i * c.i / mag2 + j * c.j / mag2 + k * c.k / mag2;
    i = i * c.r / mag2 - j * c.k / mag2 + k * c.j / mag2 - tr * c.i / mag2;
    j = ti * c.k / mag2 + j * c.r / mag2 - k * c.i / mag2 - tr * c.j / mag2;
    k = tj * c.i / mag2 + k * c.r / mag2 - tr * c.k / mag2 - ti * c.j / mag2;
    return *this;
}
template <typename T> inline Complex<T, 4> Complex<T, 4>::operator+(const Complex<T, 4> &c) {
    return {r + c.r, i + c.i, j + c.j, k + c.k};
}
template <typename T> inline Complex<T, 4> Complex<T, 4>::operator-(const Complex<T, 4> &c) {
    return {r - c.r, i - c.i, j - c.j, k - c.k};
}
template <typename T> inline Complex<T, 4> Complex<T, 4>::operator*(const Complex<T, 4> &c) {
    return {r * c.r - i * c.i - j * c.j - k * c.k, r * c.i + i * c.r + j * c.k - k * c.j, r * c.j - i * c.k + j * c.r + k * c.i,
            r * c.k + i * c.j - j * c.i + k * c.r};
}
template <typename T> inline Complex<T, 4> Complex<T, 4>::operator/(const Complex<T, 4> &c) {
    const T mag2 = SQ(c.r) + SQ(c.i) + SQ(c.j) + SQ(c.k);
    return {r * c.r / mag2 + i * c.i / mag2 + j * c.j / mag2 + k * c.k / mag2,
            i * c.r / mag2 - j * c.k / mag2 + k * c.j / mag2 - r * c.i / mag2,
            i * c.k / mag2 + j * c.r / mag2 - k * c.i / mag2 - r * c.j / mag2,
            j * c.i / mag2 + k * c.r / mag2 - r * c.k / mag2 - i * c.j / mag2};
}
template <typename T> T &Complex<T, 4>::operator[](int index) const { return *((T *)this + index); }

template struct Complex<float, 2>;
template struct Complex<float, 4>;
} // namespace math
