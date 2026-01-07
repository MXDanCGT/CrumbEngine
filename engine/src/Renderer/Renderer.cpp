#include "Renderer/Renderer.h"

#include "Shaders/BaseShader.h"
#include <filesystem>
#include <iostream>

namespace Crumb {

	MRenderer::MRenderer()
	{

	}

	MRenderer::~MRenderer()
	{

	}


	MRenderer_GL::MRenderer_GL()
	{
		PassShader = std::make_unique<BaseShader_GL>();

		//TODO decouple construction and initialisation for the renderer?
		std::cout << "Working directory: "
			<< std::filesystem::current_path() << std::endl;
		PassShader->Init("resources/Pass.vert", "resources/Pass.frag");
	}


	MRenderer_GL::~MRenderer_GL()
	{

	}

	void MRenderer_GL::Update()
	{

	}
}