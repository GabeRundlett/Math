#include "Complex.hpp"

#define SQ(x) (x * x)

namespace Math {
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
    const T tr = r, rmagSQ = SQ(c.r) + SQ(c.i);
    r = r * c.r / rmagSQ + i * c.i / rmagSQ;
    i = i * c.r / rmagSQ - tr * c.i / rmagSQ;
    return *this;
}
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator+(const Complex<T, 2> &c) { return {r + c.r, i + c.i}; }
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator-(const Complex<T, 2> &c) { return {r - c.r, i - c.i}; }
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator*(const Complex<T, 2> &c) {
    return {r * c.r - i * c.i, r * c.i + i * c.r};
}
template <typename T> inline Complex<T, 2> Complex<T, 2>::operator/(const Complex<T, 2> &c) {
    const T rmagSQ = SQ(c.r) + SQ(c.i);
    return {r * c.r / rmagSQ + i * c.i / rmagSQ, i * c.r / rmagSQ - r * c.i / rmagSQ};
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
    const T tr = r, ti = i, tj = j, rmagSQ = SQ(c.r) + SQ(c.i) + SQ(c.j) + SQ(c.k);
    r = r * c.r / rmagSQ + i * c.i / rmagSQ + j * c.j / rmagSQ + k * c.k / rmagSQ;
    i = i * c.r / rmagSQ - j * c.k / rmagSQ + k * c.j / rmagSQ - tr * c.i / rmagSQ;
    j = ti * c.k / rmagSQ + j * c.r / rmagSQ - k * c.i / rmagSQ - tr * c.j / rmagSQ;
    k = tj * c.i / rmagSQ + k * c.r / rmagSQ - tr * c.k / rmagSQ - ti * c.j / rmagSQ;
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

    const T rmagSQ = SQ(c.r) + SQ(c.i) + SQ(c.j) + SQ(c.k);
    return {r * c.r / rmagSQ + i * c.i / rmagSQ + j * c.j / rmagSQ + k * c.k / rmagSQ,
            i * c.r / rmagSQ - j * c.k / rmagSQ + k * c.j / rmagSQ - r * c.i / rmagSQ,
            i * c.k / rmagSQ + j * c.r / rmagSQ - k * c.i / rmagSQ - r * c.j / rmagSQ,
            j * c.i / rmagSQ + k * c.r / rmagSQ - r * c.k / rmagSQ - i * c.j / rmagSQ};
}
template <typename T> T &Complex<T, 4>::operator[](int index) const { return *((T *)this + index); }

template struct Complex<float, 2>;
template struct Complex<float, 4>;
} // namespace Math
