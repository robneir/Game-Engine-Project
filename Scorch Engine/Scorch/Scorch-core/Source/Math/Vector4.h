#ifndef _VECTOR4_
#define _VECTOR4_

#include <iostream>

namespace Scorch
{
namespace Math
{
	class Vector4
	{
	public:
		float m_x, m_y, m_z, m_w;

	public:
		Vector4() : m_x(0), m_y(0), m_z(0), m_w(0)
		{}

		Vector4(const float& x, const float& y, const float& z, const float& w) : m_x(x), m_y(y), m_z(z), m_w(w)
		{}

		void operator += (const Vector4& other) { m_x += other.m_x; m_y += other.m_y; m_z += other.m_z; m_w += other.m_w; }
		void operator -= (const Vector4& other) { m_x -= other.m_x; m_y -= other.m_y; m_z -= other.m_z; m_w -= other.m_w; }
		void operator *= (const float& f) { m_x *= f; m_y *= f; m_z *= f; m_w *= f; }
		void operator /= (const float& f) { m_x /= f; m_y /= f; m_z /= f; m_w /= f; }
		void operator = (const Vector4& other) { m_x = other.m_x; m_y = other.m_y; m_z = other.m_z; m_w = other.m_w;}
		bool operator == (const Vector4& other) { return(m_x == other.m_x) && (m_y == other.m_y) && (m_z == other.m_z) && (m_w == other.m_w); }
		bool operator != (const Vector4& other) { return(m_x != other.m_x) || (m_y != other.m_y) || (m_z != other.m_z) || (m_w != other.m_w); }

		inline Vector4 operator * (const float& f) { return Vector4(m_x *= f, m_y *= f, m_z *= f, m_w *= f); }
		friend inline Vector4 operator * (const float& f, const Vector4& v1) { return Vector4(v1.m_x*f, v1.m_y*f, v1.m_z*f, v1.m_w*f); }
		friend inline Vector4 operator + (const Vector4& v1, const Vector4& v2) { return Vector4(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z, v1.m_w + v2.m_w); }
		friend inline Vector4 operator - (const Vector4& v1, const Vector4& v2) { return Vector4(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z, v1.m_w - v2.m_w); }
		friend std::ostream& operator << (std::ostream& os, const Vector4& v1) {
			return os << "Vector4: (" << v1.m_x << "," << v1.m_y << "," << v1.m_z << "," << v1.m_w << ")";
		}

		float Dot(const Vector4& other) { return (m_x*other.m_x + m_y*other.m_y + m_z*other.m_z + m_w*other.m_w); }
	}; // Vector4 class

}; // Scorch namespace
}; // Math namespace


#endif
