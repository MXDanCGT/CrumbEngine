#include "World/Chunk.h"

namespace Crumb
{
	FChunk::FChunk()
	{
		ChunkPosition = (0 | 0 << 10 | 0 << 20); //Init pos to 0 0 0 

		//Init the chunk as all air
		for (int i = 0; i < sizeof(ChunkBlocks) / sizeof(ChunkBlocks[0]); ++i)
			ChunkBlocks[i] = 1; //TEMP TODO FOR THE TIME BEING WE ARE SETTING IT ALL TO DIRT TO SEE BLOCKS RENDERING CORRECTLY...
	}

}