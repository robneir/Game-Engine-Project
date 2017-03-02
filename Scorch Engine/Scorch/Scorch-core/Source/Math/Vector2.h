#ifndef _VECTOR2_
#define _VECTOR2_

#include <iostream>

namespace Scorch 
{
namespace Math
{
	class Vector2
	{
	public:
		float m_x, m_y;

	public:
		Vector2(): m_x(0), m_y(0)
		{}

		Vector2(const float& x, const float& y): m_x(x), m_y(y) 
		{}

		void operator += (const Vector2& other) { m_x += other.m_x; m_y += other.m_y; }
		void operator -= (const Vector2& other) { m_x -= other.m_x; m_y -= other.m_y; }
		void operator *= (const float& f) { m_x *= f; m_y *= f; }
		void operator /= (const float& f) { m_x /= f; m_y /= f; }
		void operator = (const Vector2& other) { m_x = other.m_x; m_y = other.m_y; }
		bool operator == (const Vector2& other) { return(m_x == other.m_x) && (m_y == other.m_y); }
		bool operator != (const Vector2& other) { return(m_x != other.m_x) || (m_y != other.m_y); }

		inline Vector2 operator * (const float& f) { return Vector2(m_x *= f, m_y *= f); }
		friend inline Vector2 operator * (const float& f, const Vector2& v1) { return Vector2(v1.m_x*f, v1.m_y*f); }
		friend inline Vector2 operator + (const Vector2& v1, const Vector2& v2) { return Vector2(v1.m_x + v2.m_x, v1.m_y + v2.m_y); }
		friend inline Vector2 operator - (const Vector2& v1, const Vector2& v2) { return Vector2(v1.m_x - v2.m_x, v1.m_y - v2.m_y); }
		friend std::ostream& operator << (std::ostream& os, const Vector2& v1) { return os << "Vector2: (" << v1.m_x << "," << v1.m_y << ")"; }

		float Length() { return sqrtf(m_x * m_x + m_y * m_y); }
		void Normalize() { *this /= Length(); }
		float Dot(const Vector2& other) { return (m_x*other.m_x + m_y*other.m_y); }
	}; // Vector2 class

}; // Scorch namespace
}; // Math namespace


#endif
