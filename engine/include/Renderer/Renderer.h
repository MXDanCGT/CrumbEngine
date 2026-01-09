#pragma once

#include "pch.h"

#include "GraphicsIncludes.h"
#include "Core/Mesh.h"

/*
* My understanding of the way "Minecraft" handles its worlds is thus:
* 
* - 
*/

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace Crumb
{
	class Camera;
	class BaseShader_GL;

	/*We are gonna attempt using SSBOs instead of VBOs, see here: https://voxel.wiki/wiki/vertex-pulling/ */
	/*Base renderer*/
	class MRenderer
	{
	public:

		MRenderer();
		~MRenderer();

		virtual void Update(std::unordered_map<int, struct FChunk*> Chunks, Camera* Cam) = 0;

		virtual void Init() = 0;
	};

	/*OpenGL specific renderer*/
	class MRenderer_GL : public MRenderer
	{
	public:

		MRenderer_GL();
		~MRenderer_GL();

		virtual void Update(std::unordered_map<int, struct FChunk*> Chunks, Camera* Cam) override;

		virtual void Init() override;

	private:

		std::unique_ptr<Mesh> m_DebugCube; //TEMP SO WE CAN SEE OURSELVES SET UP

		std::unique_ptr<BaseShader_GL> PassShader;
	};

}