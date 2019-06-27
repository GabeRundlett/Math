#include "Vector.hpp"
#include <Debug/Log.hpp>

namespace Coel {
	namespace Math {
		////////////////////////////////////
		//                                //
		//             Vector2            //
		//                                //
		////////////////////////////////////
		template <typename T>
		constexpr Vector<T, 2> &Vector<T, 2>::operator+=(const Vector<T, 2> &v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 2> &Vector<T, 2>::operator-=(const Vector<T, 2> &v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 2> &Vector<T, 2>::operator*=(const T fac)
		{
			x *= fac;
			y *= fac;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 2> &Vector<T, 2>::operator/=(const T fac)
		{
			x /= fac;
			y /= fac;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 2> Vector<T, 2>::operator+(const Vector<T, 2> &v)
		{
			return {x + v.x, y + v.y};
		}
		template <typename T>
		constexpr Vector<T, 2> Vector<T, 2>::operator-(const Vector<T, 2> &v)
		{
			return {x - v.x, y - v.y};
		}
		template <typename T>
		constexpr Vector<T, 2> Vector<T, 2>::operator*(const T fac)
		{
			return {x * fac, y * fac};
		}
		template <typename T>
		constexpr Vector<T, 2> Vector<T, 2>::operator/(const T fac)
		{
			return {x / fac, y / fac};
		}
		template <typename T>
		constexpr T &Vector<T, 2>::operator[](int index) const
		{
			DEBUG_ASSERT(index < 0 || index > 1, "Entered index too high");
			return *((T *)this + index);
		}
		////////////////////////////////////
		//                                //
		//             Vector3            //
		//                                //
		////////////////////////////////////
		template <typename T>
		constexpr Vector<T, 3> &Vector<T, 3>::operator+=(const Vector<T, 3> &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 3> &Vector<T, 3>::operator-=(const Vector<T, 3> &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 3> &Vector<T, 3>::operator*=(const T fac)
		{
			x *= fac;
			y *= fac;
			z *= fac;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 3> &Vector<T, 3>::operator/=(const T fac)
		{
			x /= fac;
			y /= fac;
			z /= fac;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 3> Vector<T, 3>::operator+(const Vector<T, 3> &v)
		{
			return {x + v.x, y + v.y, z + v.z};
		}
		template <typename T>
		constexpr Vector<T, 3> Vector<T, 3>::operator-(const Vector<T, 3> &v)
		{
			return {x - v.x, y - v.y, z - v.z};
		}
		template <typename T>
		constexpr Vector<T, 3> Vector<T, 3>::operator*(const T fac)
		{
			return {x * fac, y * fac, z * fac};
		}
		template <typename T>
		constexpr Vector<T, 3> Vector<T, 3>::operator/(const T fac)
		{
			return {x / fac, y / fac, z / fac};
		}
		template <typename T>
		constexpr T &Vector<T, 3>::operator[](int index) const
		{
			DEBUG_ASSERT(index < 0 || index > 2, "Entered index too high");
			return *((T *)this + index);
		}
		////////////////////////////////////
		//                                //
		//             Vector4            //
		//                                //
		////////////////////////////////////
		template <typename T>
		constexpr Vector<T, 4> &Vector<T, 4>::operator+=(const Vector<T, 4> &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 4> &Vector<T, 4>::operator-=(const Vector<T, 4> &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 4> &Vector<T, 4>::operator*=(const T fac)
		{
			x *= fac;
			y *= fac;
			z *= fac;
			w *= fac;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 4> &Vector<T, 4>::operator/=(const T fac)
		{
			x /= fac;
			y /= fac;
			z /= fac;
			w /= fac;
			return *this;
		}
		template <typename T>
		constexpr Vector<T, 4> Vector<T, 4>::operator+(const Vector<T, 4> &v)
		{
			return {x + v.x, y + v.y, z + v.z, w + v.w};
		}
		template <typename T>
		constexpr Vector<T, 4> Vector<T, 4>::operator-(const Vector<T, 4> &v)
		{
			return {x - v.x, y - v.y, z - v.z, w - v.w};
		}
		template <typename T>
		constexpr Vector<T, 4> Vector<T, 4>::operator*(const T fac)
		{
			return {x * fac, y * fac, z * fac, w * fac};
		}
		template <typename T>
		constexpr Vector<T, 4> Vector<T, 4>::operator/(const T fac)
		{
			return {x / fac, y / fac, z / fac, w / fac};
		}
		template <typename T>
		constexpr T &Vector<T, 4>::operator[](int index) const
		{
			DEBUG_ASSERT(index < 0 || index > 3, "Entered index too high");
			return *((T *)this + index);
		}

		template struct Vector<float, 2>;
		template struct Vector<float, 3>;
		template struct Vector<float, 4>;

		template struct Vector<double, 2>;
		template struct Vector<double, 3>;
		template struct Vector<double, 4>;
	} // namespace Math
} // namespace Coel
