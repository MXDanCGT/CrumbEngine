#pragma once

#include "pch.h"

#include "Core/Mesh.h"

/*
* My understanding of the way "Minecraft" handles its worlds is thus:
* 
* - 
*/
namespace Crumb
{
	class BaseShader_GL;

	/*We are gonna attempt using SSBOs instead of VBOs, see here: https://voxel.wiki/wiki/vertex-pulling/ */
	/*Base renderer*/
	class MRenderer
	{
	public:

		MRenderer();
		~MRenderer();

		virtual void Update(std::unordered_map<int, struct FChunk*> Chunks) = 0;

		virtual void Init() = 0;
	};

	/*OpenGL specific renderer*/
	class MRenderer_GL : public MRenderer
	{
	public:

		MRenderer_GL();
		~MRenderer_GL();

		virtual void Update(std::unordered_map<int, struct FChunk*> Chunks) override;

		virtual void Init() override;

	private:

		std::unique_ptr<Mesh> DebugCube; //TEMP SO WE CAN SEE OURSELVES SET UP

		std::unique_ptr<BaseShader_GL> PassShader;
	};

}