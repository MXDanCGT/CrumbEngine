#pragma once

#include "pch.h"

namespace Crumb
{
	class BaseShader_GL;


	/*Base renderer*/
	class MRenderer
	{
	public:

		MRenderer();
		~MRenderer();

		virtual void Update() = 0;
	};

	/*OpenGL specific renderer*/
	class MRenderer_GL : public MRenderer
	{
	public:

		MRenderer_GL();
		~MRenderer_GL();

		virtual void Update() override;

	private:

		std::unique_ptr<BaseShader_GL> PassShader;
	};

}