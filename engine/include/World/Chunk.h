#pragma once

#include "pch.h"

#include "Core/Mesh.h"
#include "glm/glm.hpp"
namespace Crumb
{
	/*
	* Chunks are what we partition the world into - each chunk is a section of voxels...
	* Chunks are 4100 bytes (4.1kb)
	*/


	struct FChunk
	{

		FChunk();

		/*Chunks are stored */
		unsigned char ChunkBlocks[16 * 16 * 16]; /*For our default, 16x16x16 = 4096 bytes(32 Kibibytes)*/

		glm::vec3 WorldPos; /*Global position of this chunk*/

		/*Create a chunk mesh (Minecraft Style)*/

		void CreateChunkMesh();

	};
}