#pragma once

#include "pch.h"

#include "Core/Mesh.h"

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

		int ChunkPosition; /*Int to represent chunk position, remember we are packing our positions in here, i.e.: position.x | position.y << 10 | position.z << 20*/

		/*Chunks */

	};
}