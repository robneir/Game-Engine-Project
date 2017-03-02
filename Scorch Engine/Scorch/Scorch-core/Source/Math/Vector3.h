#ifndef _VECTOR3_
#define _VECTOR3_

#include <iostream>

namespace Scorch
{
namespace Math
{
	class Vector3
	{
	public:
		float m_x, m_y, m_z;

	public:
		Vector3() : m_x(0), m_y(0), m_z(0)
		{}

		Vector3(const float& x, const float& y, const float& z) : m_x(x), m_y(y), m_z(z)
		{}

		void operator += (const Vector3& other) { m_x += other.m_x; m_y += other.m_y; m_z += other.m_z; }
		void operator -= (const Vector3& other) { m_x -= other.m_x; m_y -= other.m_y; m_z -= other.m_z; }
		void operator *= (const float& f) { m_x *= f; m_y *= f; m_z *= f; }
		void operator /= (const float& f) { m_x /= f; m_y /= f; m_z /= f; }
		void operator = (const Vector3& other) { m_x = other.m_x; m_y = other.m_y; m_z = other.m_z; }
		bool operator == (const Vector3& other) { return(m_x == other.m_x) && (m_y == other.m_y) && (m_z == other.m_z); }
		bool operator != (const Vector3& other) { return(m_x != other.m_x) || (m_y != other.m_y) || (m_z != other.m_z); }

		inline Vector3 operator * (const float& f) { return Vector3(m_x *= f, m_y *= f, m_z *= f); }
		friend inline Vector3 operator * (const float& f, const Vector3& v1) { return Vector3(v1.m_x*f, v1.m_y*f, v1.m_z*f); }
		friend inline Vector3 operator + (const Vector3& v1, const Vector3& v2) { return Vector3(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z); }
		friend inline Vector3 operator - (const Vector3& v1, const Vector3& v2) { return Vector3(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z); }
		friend std::ostream& operator << (std::ostream& os, const Vector3& v1) { return os << "Vector3: (" << v1.m_x << "," << v1.m_y << "," << v1.m_z << ")"; }

		float Length() { return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z);}
		void Normalize() { *this /= Length(); }
		float Dot(const Vector3& other) { return (m_x*other.m_x + m_y*other.m_y + m_z*other.m_z); }
		Vector3 CrossProduct(const Vector3 &v)
		{
			return Vector3(
				m_y * v.m_z - m_z * v.m_y,
				m_z * v.m_x - m_x * v.m_z,
				m_x * v.m_y - m_y * v.m_x);
		}
	}; // Vector3 class

}; // Scorch namespace
}; // Math namespace


#endif
