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

		//Make sure our shader is up to date TODO ALLOW THIS TO HAPPEN ELSEWHERE??
		PassShader->SetShaderParams(m_DebugCube->GetWorldMat(), Cam->GetViewMatrix(), Cam->GetProjMatrix());

		const unsigned int MWLoc = glGetUniformLocation(PassShader->GetID(), "MatWorld");
		glUniformMatrix4fv(MWLoc, 1, false, &m_DebugCube->GetWorldMat()[0][0]);

		unsigned int MVLoc = glGetUniformLocation(PassShader->GetID(), "MatView");
		glUniformMatrix4fv(MVLoc, 1, false, &Cam->GetViewMatrix()[0][0]);

		unsigned int MPLoc = glGetUniformLocation(PassShader->GetID(), "MatProj");
		glUniformMatrix4fv(MPLoc, 1, false, &Cam->GetProjMatrix()[0][0]);


		m_DebugCube->Render();


		//OLD DEBUG CODE ^^^



	}

	void MRenderer_GL::Init()
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_CULL_FACE);

		//DO this here so we can be sure we've initialised OpenGL in our GLFW window first
		PassShader->Init("resources/Pass.vert", "resources/Pass.frag");
		m_DebugCube = std::make_unique<Mesh>(); //Want to create this after OpenGL init is done
	}
}