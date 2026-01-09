#include "World/World.h"

#include "pch.h"
#include "World/Chunk.h"
#include "World/World.h"



namespace Crumb
{

	World::World(bool bAutoGenerate)
	{
		MemPool = new MemChunk<FChunk>(1);
		std::cout << "Memory pool for world reserved of size: " << MemPool->m_ChunkCount * sizeof(FChunk) << " bytes \n";
		LoadedChunks = {};

		//Fix cos shit was hitting the fan
		//if (bAutoGenerate)
		//	GenerateWorld();
	}


	World::~World()
	{

	}

	FChunk* World::LoadChunk(int PosX, int PosY, int PosZ)
	{
		//NTS - MINECRAFT LOADS / UNLOADS CHUNKS EVERY TIME AN "UPDATE" HAPPENS 
		int PosPull = PackPosition(PosX, PosY, PosZ);

		//If this chunks already in our loaded chunks, return it
		if (LoadedChunks.find(PosPull) != LoadedChunks.end())
			return LoadedChunks[PosPull];


		//New chunk from our memory pool...
		FChunk* NewChunk = MemPool->allocate();
		assert(NewChunk);

		//Offset position by 8 in each axis we want to from the centre of the world
		//TODO INIT LOGIC, IF THIS IS GENERATE WORLD USE SEED ELSE READ FROM A FILE TODO SAVING ETC. ETC.

		NewChunk->m_WorldPos = { PosX, PosY, PosZ };
		NewChunk->CreateChunkMesh(); //Create our chunk mesh after its been loaded...
		LoadedChunks[PosPull] = NewChunk;

		return NewChunk;
	}

	void World::UnloadChunk(int PosX, int PosY, int PosZ)
	{
		int PosPull = PackPosition(PosX, PosY, PosZ);

		auto ChunkIt = LoadedChunks.find(PosPull);
		if (ChunkIt != LoadedChunks.end())
		{
			MemPool->deallocate(LoadedChunks[PosPull]);
			LoadedChunks.erase(ChunkIt);
		}
	}

	void World::GenerateWorld()
	{
		//FOR NOW, we are just gonna do the mem allocation and hard code a chunk

		//Make 1 chunks!
		LoadChunk(0.f, 0.f, 0.f);
		//LoadChunk(10.f, 0.f, 0.f);
		//LoadChunk(10.f, 10.f, 0.f);
		//LoadChunk(0.f,10.f,0.f);
	}


	void World::Update()
	{
		//TODO MOVEMENT CALCS AND CHUNKS LOADING / UNLOADING...
	}
}