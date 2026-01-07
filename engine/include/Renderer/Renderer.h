#pragma once

#include "pch.h"

namespace Crumb
{
	/*Base renderer*/
	class MRenderer
	{
	public:

		MRenderer();
		~MRenderer();

		virtual void Update();
	};

	/*OpenGL specific renderer*/
	class MRenderer_GL : public MRenderer
	{
	public:

		MRenderer_GL();
		~MRenderer_GL();

		virtual void Update() override;
	};

}