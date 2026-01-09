#include "Shaders/BaseShader.h"

#include <fstream>
#include <sstream>

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{
	BaseShader::BaseShader()
	{
		ProgramNumber = 0;
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
			std::cout << "ERROR SHADER COMPILATION FAILED\n" << Log << "\n";
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
			std::cout << "ERROR SHADER FILE NOT FOUND: " << FilePath << "\n";
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

		ProgramNumber = glCreateProgram();
		glAttachShader(ProgramNumber, VSNum);
		glAttachShader(ProgramNumber, FSNum);
		glLinkProgram(ProgramNumber);

		assert(PrintShaderCompileStatus(ProgramNumber));

		
		//We can now delete the shader objects, they are compiled in the program, we no longer depend on them...
		glDetachShader(ProgramNumber, VSNum);
		glDetachShader(ProgramNumber, FSNum);

		glDeleteShader(VSNum);
		glDeleteShader(FSNum);


		return true;
	}


	void BaseShader_GL::SetShaderParams(glm::mat4 WorldMatrix, glm::mat4 ViewMatrix, glm::mat4 ProjMatrix)
	{
		const unsigned int MWLoc = glGetUniformLocation(ProgramNumber, "MatWorld");
		glUniformMatrix4fv(MWLoc, 1, false, &WorldMatrix[0][0]);

		unsigned int MVLoc = glGetUniformLocation(ProgramNumber, "MatView");
		glUniformMatrix4fv(MVLoc, 1, false, &ViewMatrix[0][0]);

		unsigned int MPLoc = glGetUniformLocation(ProgramNumber, "MatProj");
		glUniformMatrix4fv(MPLoc, 1, false, &ProjMatrix[0][0]);


	}

}