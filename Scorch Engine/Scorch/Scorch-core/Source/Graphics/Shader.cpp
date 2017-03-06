#include "Shader.h"


namespace Scorch
{
namespace Graphics
{
	using namespace Utilities;
	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		m_vertPath = vertPath;
		m_fragPath = fragPath;
		m_shaderID = load();
	}

	Shader::~Shader()
	{

	}

	void Shader::Enable() const
	{
		glUseProgram(m_shaderID);
	}

	void Shader::Disable() const
	{
		glUseProgram(0);
	}

	bool Shader::checkShaderCompileError(GLuint shader)
	{
		GLint success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			GLint logSize = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
			std::vector<GLchar> errorLog(logSize);
			glGetShaderInfoLog(shader, logSize, &logSize, &errorLog[0]);
			std::cout << &errorLog[0] << std::endl;
			std::cout << "FAILED to compile vertex shader." << std::endl;
			glDeleteShader(shader);
			return false;
		}
		return true;
	}

	GLuint Shader::load()
	{
		// A program object is an object to which shader objects can be attached. 
		GLuint program = glCreateProgram();
		GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vsString = FileUtils::read_file(m_vertPath);
		std::string fsString = FileUtils::read_file(m_fragPath);
		const char* vsCharStr = vsString.c_str();
		const char* fsCharStr = fsString.c_str();


		// compile vertex shader
		glShaderSource(vShader, 1, &vsCharStr, NULL);
		glCompileShader(vShader);
		if (!checkShaderCompileError(vShader))
			return 0;

		// compile fragment shader.
		glShaderSource(fShader, 1, &fsCharStr, NULL);
		glCompileShader(fShader);
		if (!checkShaderCompileError(fShader))
			return 0;

		// attach shaders to program.
		glAttachShader(program, vShader);
		glAttachShader(program, fShader);

		// link program.
		glLinkProgram(program);
		glValidateProgram(program);

		// delete shaders since they are not needed anymore.
		glDeleteShader(vShader);
		glDeleteShader(fShader);

		return program;
	}

	GLint Shader::getUniformLocation(const GLchar* name)
	{
		return glGetUniformLocation(m_shaderID, name);
	}
	void Shader::setUniformInt(const GLchar* name, const int& num)
	{
		glUniform1i(getUniformLocation(name), num);
	}
	void Shader::setUniformFloat(const GLchar* name, const float& f)
	{
		glUniform1f(getUniformLocation(name), f);
	}
	void Shader::setUniformVec2(const GLchar* name, const Vector2& v)
	{
		glUniform2f(getUniformLocation(name), v.m_x, v.m_y);
	}
	void Shader::setUniformVec3(const GLchar* name, const Vector3& v)
	{
		glUniform3f(getUniformLocation(name), v.m_x, v.m_y, v.m_z);
	}
	void Shader::setUniformVec4(const GLchar* name, const Vector4& v)
	{
		glUniform4f(getUniformLocation(name), v.m_x, v.m_y, v.m_z, v.m_w);
	}
	void Shader::setUniformMat4(const GLchar* name, const Matrix4x4& matrix)
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.m[0]);
	}

}; // Scorch
}; // Graphics