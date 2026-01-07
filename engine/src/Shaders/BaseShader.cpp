#include "Shaders/BaseShader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{
	BaseShader::BaseShader()
	{
	}

	BaseShader::~BaseShader()
	{
	}

	BaseShader_GL::BaseShader_GL()
	{
	}

	BaseShader_GL::~BaseShader_GL()
	{
	}

	int BaseShader_GL::PrintShaderCompileStatus(int ProgramNumber)
	{

		int Out;
		char Log[512];
		glGetShaderiv(ProgramNumber, GL_COMPILE_STATUS, &Out);
		if (!Out)
		{
			glGetShaderInfoLog(ProgramNumber, 512, NULL, Log);
			std::cerr << "ERROR::SHADER COMPILATION FAILED\n" << Log << std::endl;
		}

		return Out;
	}

	//TODO is it more efficient to pass in the correct file type, or to work it out from the file extension (i.e.: .vs -> Vertex, .fs -> Fragment)
	int BaseShader_GL::CompileShader(const char* ShaderFileName, GLenum ShaderType)
	{
		int ShaderNum = glCreateShader(ShaderType);
		glShaderSource(ShaderNum, 1, &ShaderFileName, NULL);
		glCompileShader(ShaderNum);


		PrintShaderCompileStatus(ShaderNum);

		return ShaderNum;
	}

	//Really trying to not get in the habit of calling it "pixel shader" as GL as a whole seems to prefer calling it frag, might as well stick to their tradition
	bool BaseShader_GL::Init(const char* FragmentShader, const char* VertexShader)
	{
		int VSNum = CompileShader(VertexShader, GL_VERTEX_SHADER);
		int FSNum = CompileShader(FragmentShader, GL_FRAGMENT_SHADER);

		int ProgNum = glCreateProgram();
		glAttachShader(ProgNum, VSNum);
		glAttachShader(ProgNum, FSNum);

		assert(PrintShaderCompileStatus(ProgNum));

		
		//We can now delete the shader objects, they are compiled in the program, we no longer depend on them...

		glDeleteShader(VSNum);
		glDeleteShader(FSNum);


		return true;
	}
}