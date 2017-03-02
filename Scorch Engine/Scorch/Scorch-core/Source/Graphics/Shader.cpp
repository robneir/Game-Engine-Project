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
		GLint success;
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			GLint logSize = 0;
			glGetShaderiv(vShader, GL_INFO_LOG_LENGTH, &logSize);
			std::vector<GLchar> errorLog(logSize);
			glGetShaderInfoLog(vShader, logSize, &logSize, &errorLog[0]);
			std::cout << &errorLog[0] << std::endl;
			std::cout << "FAILED to compile vertex shader." << std::endl;
			glDeleteShader(vShader);
			return 0;
		}

		// compile fragment shader.
		glShaderSource(fShader, 1, &fsCharStr, NULL);
		glCompileShader(fShader);
		success;
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			GLint logSize = 0;
			glGetShaderiv(fShader, GL_INFO_LOG_LENGTH, &logSize);
			std::vector<GLchar> errorLog(logSize);
			glGetShaderInfoLog(fShader, logSize, &logSize, &errorLog[0]);
			std::cout << &errorLog[0] << std::endl;
			std::cout << "FAILED to compile fragment shader." << std::endl;
			glDeleteShader(fShader);
			return 0;
		}

		// attach shaders to program
		glAttachShader(program, vShader);
		glAttachShader(program, fShader);

		// link program
		glLinkProgram(program);
		glValidateProgram(program);

		// delete shaders since they are not needed anymore
		glDeleteShader(vShader);
		glDeleteShader(fShader);

		return program;
	}
}
}