#ifndef _MATRIX4x4_
#define _MARTIX4x4_

#include <iostream>

#include "Vector3.h"
#include "Vector4.h"
#include "MathHelpers.h"

namespace Scorch
{
namespace Math
{
	/* Matrix is coloumn major because OpenGL takes coloumn major. */
	class Matrix4x4
	{
	public:

		union
		{
			float m[4][4]; // m[row][col]
			Vector4 col[4];
		};

		Matrix4x4()
		{
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					m[y][x] = 0;
		}

		Matrix4x4(const Matrix4x4 &copy)
		{
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					m[y][x] = copy.m[y][x];
		}

		Matrix4x4(float diagnol) 
		{
			Clear();
			m[0][0] = m[1][1] = m[2][2] = m[3][3] = diagnol;
		}

		Matrix4x4 operator*(const float& f)
		{
			Matrix4x4 res = (*this);
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					res.m[y][x] *= f;
			return res;
		}

		friend Matrix4x4 operator*(const float& f, const Matrix4x4& m)
		{
			Matrix4x4 res = m;
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					res.m[y][x] *= f;
			return res;
		}

		friend Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right)
		{
			Matrix4x4 res;
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float dotOfRowCol = 0;
					for (int z = 0; z < 4; z++)
					{
						dotOfRowCol += left.m[y][z] * right.m[z][x];
					}
					res.m[y][x] = dotOfRowCol;
				}
			}
			return res;
		}

		void operator*=(const Matrix4x4& other)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float dotOfRowCol = 0;
					for (int z = 0; z < 4; z++)
					{
						dotOfRowCol += m[y][z] * other.m[z][x];
					}
					m[y][x] = dotOfRowCol;
				}
			}
		}

		friend std::ostream& operator << (std::ostream& os, const Matrix4x4& mat) 
		{
			os << "| "<< mat.m[0][0] << ", " << mat.m[1][0] << ", " << mat.m[2][0] << ", " << mat.m[3][0] << " |\n";
			os << "| " << mat.m[0][1] << ", " << mat.m[1][1] << ", " << mat.m[2][1] << ", " << mat.m[3][1] << " |\n";
			os << "| " << mat.m[0][2] << ", " << mat.m[1][2] << ", " << mat.m[2][2] << ", " << mat.m[3][2] << " |\n";
			os << "| " << mat.m[0][3] << ", " << mat.m[1][3] << ", " << mat.m[2][3] << ", " << mat.m[3][3] << " |\n";
			return os;
		}

		void Clear()
		{
			std::memset((void *)m, 0, sizeof(m));
		}

		void LoadIdentity()
		{
			Clear();
			m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
		}

		static Matrix4x4 Identity()
		{
			return Matrix4x4(1.0f);
		}

		static Matrix4x4 Orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			Matrix4x4 res(1.0f);
			res.m[0][0] = 2.0f / (right - left);
			res.m[1][1] = 2.0f / (top - bottom);
			res.m[2][2] = -2.0f / (far - near);
			res.m[0][3] = -(right + left) / (right - left);
			res.m[1][3] = -(top + bottom) / (top - bottom);
			res.m[2][3] = -(far + near) / (far - near);
		}

		static Matrix4x4 Perspective(float fov, float aspectRatio, float near, float far)
		{
			Matrix4x4 res;
			float q = 1.0f / tan(ToRadians(0.5f * fov));
			float a = q / aspectRatio;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			res.m[0][0] = a;
			res.m[1][1] = q;
			res.m[2][2] = b;
			res.m[2][3] = c;
			res.m[3][2] = -1.0f;

			return res;
		}

		static Matrix4x4 Translation(const Vector3& translation)
		{
			Matrix4x4 res(1.0f);
			res.m[3][0] = translation.m_x;
			res.m[3][1] = translation.m_y;
			res.m[3][2] = translation.m_z;
			return res;
		}

		static Matrix4x4 Rotation(float angle, const Vector3& axis)
		{
			Matrix4x4 res(1.0f);
			float r = ToRadians(angle);
			float s = sin(r);
			float c = cos(r);
			float omc = 1.0f - c;

			float x = axis.m_x;
			float y = axis.m_y;
			float z = axis.m_z;

			res.m[0][0] = x * x * omc + c;
			res.m[1][0] = x * y * omc + z * s;
			res.m[2][0] = x * z * omc - y * s;

			res.m[0][1] = x * y * omc - z * s;
			res.m[1][1] = y * y * omc + c;
			res.m[2][1] = y * z * omc + x * s;

			res.m[0][2] = x * z * omc + y *s;
			res.m[1][2] = y * z * omc - x * s;
			res.m[2][2] = z * z * omc + c;
			return res;
		}

		static Matrix4x4 Scale(const Vector3& scale)
		{
			Matrix4x4 res(1.0f);
			res.m[0][0] = scale.m_x;
			res.m[1][1] = scale.m_y;
			res.m[2][2] = scale.m_z;
			return res;
		}
	}; // Matrix4x4 class

}; // Scorch namespace
}; // Math namespace


#endif