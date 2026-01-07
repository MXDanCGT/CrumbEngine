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

						/*To this day I have not a fucking scooby what a hwnd is*/
		virtual bool Init(const char* FragmentShader, const char* VertexShader) = 0;

	protected:

		/*Compile a given shader*/
		virtual int CompileShader(const char* ShaderFileName, GLenum Type) = 0;

	};



	class BaseShader_GL : public BaseShader
	{
	public:

		BaseShader_GL();
		~BaseShader_GL();

		/*Little helper function to print shader compile stuffs incase it goes wrong*/
		int PrintShaderCompileStatus(int ProgramNumber);

		virtual bool Init(const char* FragmentShader, const char* VertexShader) override;


		virtual int CompileShader(const char* ShaderFileName, GLenum Type) override;
	};

}