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


	MRenderer_GL::MRenderer_GL() : MRenderer::MRenderer()
	{
		PassShader = std::make_unique<BaseShader_GL>();
	}


	MRenderer_GL::~MRenderer_GL()
	{

	}

	void MRenderer_GL::Update(std::unordered_map<int, struct FChunk*> Chunks)
	{
		//Based on the input loaded chunks, we will draw cubes for them 
		//TEMP - FOR NOW UNTILL WE GET TEXTURES BLOCKS WILL BE A SINGLE COLOUR TO REPRESENT THEM (DICTIONARY IN SHADERS)
		glUseProgram(PassShader->GetID());
		static const GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
		};

		GLuint vertexbuffer;
		// Generate 1 buffer, put the resulting identifier in vertexbuffer
		glGenBuffers(1, &vertexbuffer);
		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glDisableVertexAttribArray(0);
	}


	void MRenderer_GL::Init()
	{
		//DO this here so we can be sure we've initialised OpenGL in our GLFW window first
		PassShader->Init("resources/Pass.vert", "resources/Pass.frag");
		DebugCube = std::make_unique<Mesh>(); //Want to create this after OpenGL init is done
	}
}