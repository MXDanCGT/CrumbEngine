#include "Renderer/Renderer.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "Shaders/BaseShader.h"
#include <filesystem>
#include <iostream>

#include "Core/Camera.h"

namespace Crumb {

	MRenderer::MRenderer()
	{
	}

	MRenderer::~MRenderer()
	{
	}


	MRenderer_GL::MRenderer_GL() : MRenderer::MRenderer()
	{
		PassShader = std::make_unique<BaseShader_GL>();
	}


	MRenderer_GL::~MRenderer_GL()
	{

	}

	void MRenderer_GL::Update(std::unordered_map<int, struct FChunk*> Chunks, Camera* Cam)
	{
		//Based on the input loaded chunks, we will draw cubes for them 
		//TEMP - FOR NOW UNTILL WE GET TEXTURES BLOCKS WILL BE A SINGLE COLOUR TO REPRESENT THEM (DICTIONARY IN SHADERS)
		glUseProgram(PassShader->GetID());

		/*Wec call set shader params here*/
		//TODO ALLOW APP PROG TO DEFINE THEIR OWN SHADER AND CHANGE THROUGH USE OF A DEFAULT SHADER

		for (std::pair<int, FChunk*> i : Chunks)
		{
			PassShader->SetShaderParams(i.second->GetWorldMat(), Cam->GetViewMatrix(), Cam->GetProjMatrix());

			i.second->RenderChunk();
		}


	}

	void MRenderer_GL::Init()
	{
		assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); //Moved this here so all specifically GL is in the renderer, (almost) all GLFW is in the window manager...

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_CULL_FACE);

		//DO this here so we can be sure we've initialised OpenGL in our GLFW window first
		PassShader->Init("resources/Pass.vert", "resources/Pass.frag");
	}
}