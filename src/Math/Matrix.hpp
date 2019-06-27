#pragma once
#include "Vector.hpp"

namespace Coel {
	namespace Math {
		template <typename T, int Rows, int Cols>
		struct Matrix;

		template <typename T>
		struct Matrix<T, 2, 2> {
			Vector<T, 2> data[2];

			constexpr Matrix();
			constexpr Matrix(const Matrix<T, 2, 2> &m);
			constexpr Matrix(const Vector<T, 2> &v1,
				const Vector<T, 2> &v2);

			constexpr Vector<T, 2> operator[](int index) const;
		};

		template <typename T>
		struct Matrix<T, 3, 3> {
			Vector<T, 3> data[3];

			constexpr Matrix();
			constexpr Matrix(const Matrix<T, 3, 3> &m);
			constexpr Matrix(const Vector<T, 3> &v1,
				const Vector<T, 3> &v2,
				const Vector<T, 3> &v3);

			constexpr Vector<T, 3> operator[](int index) const;
		};

		template <typename T>
		struct Matrix<T, 4, 4> {
			Vector<T, 4> data[4];

			constexpr Matrix();
			constexpr Matrix(const Matrix<T, 4, 4> &m);
			constexpr Matrix(const Vector<T, 4> &v1,
				const Vector<T, 4> &v2,
				const Vector<T, 4> &v3,
				const Vector<T, 4> &v4);

			constexpr Matrix<T, 4, 4> &operator+=(const Matrix<T, 4, 4> &m);
			constexpr Matrix<T, 4, 4> &operator-=(const Matrix<T, 4, 4> &m);
			constexpr Matrix<T, 4, 4> &operator*=(const Matrix<T, 4, 4> &m);
			constexpr Vector<T, 4> operator[](int index) const;

			constexpr static Matrix<T, 4, 4> ortho(T l, T r, T b, T t, T n, T f);
			constexpr static Matrix<T, 4, 4> translation(const Vector<T, 3> delta);
			constexpr static Matrix<T, 4, 4> rotation(float angle, const Vector<T, 3> axis);
			constexpr static Matrix<T, 4, 4> scalar(const Vector<T, 3> factor);
		};
	} // namespace Math
} // namespace Coel
