#pragma once

#include "pch.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{
	/*
	* Shaders are classes that compile and execute our GLSL shaders
	*/

	class BaseShader
	{
	public:
		BaseShader();
		~BaseShader();

		virtual bool Init(const char* VertexShaderFile, const char* FragmentShaderFile) = 0;

	protected:

		/*Compile a given shader*/
		virtual int CompileShader(const char* ShaderFileCode, GLenum Type) = 0;

	};



	class BaseShader_GL : public BaseShader
	{
	public:

		BaseShader_GL();
		~BaseShader_GL();

		/*Little helper function to print shader compile stuffs incase it goes wrong*/
		int PrintShaderCompileStatus(int ProgramNumber);

		virtual bool Init(const char* VertexShaderFile, const char* FragmentShaderFile) override;


		virtual int CompileShader(const char* ShaderFileCode, GLenum Type) override;

		/*We read these files as strings and */
		std::string ReadShaderFile(const char* FilePath);
	};

}