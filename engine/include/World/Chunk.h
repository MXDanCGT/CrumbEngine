#pragma once

#include "pch.h"

#include "Core/Mesh.h"
#include "glm/glm.hpp"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace Crumb
{
	/*
	* Chunks are what we partition the world into - each chunk is a section of voxels...
	* Chunks are TODO RECALC SIZE
	*/


	struct FChunk
	{

		FChunk();

		/*Verticies positions...*/
		std::vector< glm::vec3> Verts;

		/*Vertex Indicies*/
		std::vector<unsigned int> Indices;

		/*Chunks are stored */
		unsigned char ChunkBlocks[16 * 16 * 16]; /*For our default, 16x16x16 = 4096 bytes(32 Kibibytes)*/

		glm::vec3 m_WorldPos; /*Global position of this chunk*/

		/*Create a chunk mesh (Minecraft Style)*/
		void CreateChunkMesh();

		/*Get the pos in that 1D array up their for the LOCAL coordinate of the block*/
		inline int GetBlockIndex(int x, int y, int z) { return x + (16 * y + (16 * z)); }

		/*For adding indexs (always same pattern, this just increments)*/
		int m_FaceCount;
		//I know ive forgotten to do "m_" in a number of places, oh well...

		void AddIndexes();

		glm::mat4 GetWorldMat();

		void RenderChunk();

		/*The actual vertex buffer*/
		unsigned int m_ChunkVertBuffer;
		/*The actual index buffer*/
		unsigned int m_ChunkIndBuffer;

		unsigned int m_VertArrayID;

	};
}