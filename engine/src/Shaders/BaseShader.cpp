#include "Shaders/BaseShader.h"

#include <fstream>
#include <sstream>

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
			std::cerr << "ERROR SHADER COMPILATION FAILED\n" << Log << "\n";
		}
		return Out;
	}

	//TODO is it more efficient to pass in the correct file type, or to work it out from the file extension (i.e.: .vs -> Vertex, .fs -> Fragment)
	int BaseShader_GL::CompileShader(const char* ShaderFileCode, GLenum ShaderType)
	{
		int ShaderNum = glCreateShader(ShaderType);
		glShaderSource(ShaderNum, 1, &ShaderFileCode, NULL);
		glCompileShader(ShaderNum);


		PrintShaderCompileStatus(ShaderNum);

		return ShaderNum;
	}

	std::string BaseShader_GL::ReadShaderFile(const char* FilePath)
	{
		std::ifstream ShaderFile(FilePath);
		if (!ShaderFile.is_open())
		{
			std::cerr << "ERROR SHADER FILE NOT FOUND: " << FilePath << "\n";
		}

		std::stringstream FileBuffer;
		FileBuffer << ShaderFile.rdbuf();
		return FileBuffer.str();
	}

	//Really trying to not get in the habit of calling it "pixel shader" as GL as a whole seems to prefer calling it frag, might as well stick to their tradition
	bool BaseShader_GL::Init(const char* VertexShaderFile, const char* FragmentShaderFile)
	{
		std::string VertexCode = ReadShaderFile(VertexShaderFile);
		std::string FragmentCode = ReadShaderFile(FragmentShaderFile);

		int VSNum = CompileShader(VertexCode.c_str(), GL_VERTEX_SHADER);
		int FSNum = CompileShader(FragmentCode.c_str(), GL_FRAGMENT_SHADER);

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