#pragma once

#include "pch.h"

#include "Core/MemoryPool.h"
#include "Chunk.h"

namespace Crumb
{
	/*
	* THE WORLD
	*/
	class World
	{
	public:

	
		World(bool bAutoGenerate = true);
		~World();

		virtual void GenerateWorld();

		/*Update the world!*/
		virtual void Update();

		/*Chunk loading function exposed to the app programmer*/
		FChunk* LoadChunk(int PosX, int PosY, int PosZ = 0);

		/*Chunk deloading function exposed to the app programmer*/
		void UnloadChunk(int PosX, int PosY, int PosZ = 0);

		/*Get a pointer to the chunks we should currently have loaded...*/
		inline std::unordered_map<int, struct FChunk*> GetLoadedChunks() { return LoadedChunks; };

	private:

		/**
		* The pool of memory allocated on construction where we put all our loaded world chunks.
		* 
		* This has a number of benefits, including ensuring all of it is in one contiguos spot in memory
		* 
		* If you wanna read more abt it, you can do much worse than voxel wiki (as always)
		* https://voxel.wiki/wiki/rendering/
		*/
					//TODO CALC NECESSARY POOLED MEMORY BASED ON RENDER DISTANCE
		MemChunk<FChunk>* MemPool;

		/*The chunks loaded into the map - the actual pointers*/
		std::unordered_map<int, struct FChunk*> LoadedChunks;
	};

}