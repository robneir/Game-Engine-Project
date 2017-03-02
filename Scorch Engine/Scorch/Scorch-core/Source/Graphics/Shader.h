#ifndef _SHADER_
#define _SHADER_

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../Utilities/FileUtils.h"

namespace Scorch
{
namespace Graphics
{
	/* manages loading shader files and sending data to  the
		shader and enabling and disabling shaders. Also stores 
		uniform locations. */
	class Shader
	{
	private:
		GLuint m_shaderID;
		const char* m_vertPath;
		const char* m_fragPath;

	public:
		Shader(const char* vertexPath, const char* fragPath);
		~Shader();

		void Enable() const;
		void Disable() const;

	private:
		GLuint load();
	};


}; // Scorch namespace
}; // Graphics namespace

#endif
