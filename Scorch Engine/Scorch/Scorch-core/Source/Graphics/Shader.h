#ifndef _SHADER_
#define _SHADER_

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../Utilities/FileUtils.h"
#include "../Math/Math.h"

namespace Scorch
{
namespace Graphics
{
	using namespace Math;

	/* manages loading shader files and sending data to  the
		shader and enabling and disabling shaders. Also stores 
		uniform locations. */
	class Shader
	{
	public:
		GLuint m_shaderID;
		const char* m_vertPath;
		const char* m_fragPath;

	public:
		Shader(const char* vertexPath, const char* fragPath);
		~Shader();

		void Enable() const;
		void Disable() const;

		void setUniformInt(const GLchar* name, const int& num);
		void setUniformFloat(const GLchar* name, const float& f);
		void setUniformVec2(const GLchar* name, const Vector2& v);
		void setUniformVec3(const GLchar* name, const Vector3& v);
		void setUniformVec4(const GLchar* name, const Vector4& v);
		void setUniformMat4(const GLchar* name, const Matrix4x4& matrix);

	private:
		bool checkShaderCompileError(GLuint shader);
		GLuint load();
		GLint getUniformLocation(const GLchar* name);
	};


}; // Scorch namespace
}; // Graphics namespace

#endif
