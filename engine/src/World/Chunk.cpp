#include "World/Chunk.h"

#include "glm/glm.hpp"

namespace Crumb
{
	FChunk::FChunk()
	{
		//This works for CHUNK COORDINATES as the sign bit is not needed - coords range 0-ChunkSize with 0 being bottom left (*** MIGHT HAVE CHANGED IN IMPLEM AND NOT UPDATED COMMENTS)
		WorldPos = { 0.f,0.f,0.f }; //Init pos to 0 0 0 

		//Init the chunk as all air by default
		for (int i = 0; i < sizeof(ChunkBlocks) / sizeof(ChunkBlocks[0]); ++i)
			ChunkBlocks[i] = 1; //TEMP TODO FOR THE TIME BEING WE ARE SETTING IT ALL TO DIRT TO SEE BLOCKS RENDERING CORRECTLY...
	}

	void FChunk::CreateChunkMesh()
	{
		/*Is there a better way to do this than thiss?*/
		
		/*We are just gonna do naively what minecraft does - put all the cube faces in one mesh, and skipping if the face's neighbour is not air...*/

		for (int x = 0; x < 16; ++x)
		{
			for (int y = 0; y < 16; ++y)
			{
				for (int z = 0; z < 16; ++z)
				{

				}
			}
		}
	}
}