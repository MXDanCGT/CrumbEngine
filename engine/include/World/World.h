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

	
		World(bool bAutoGenerate = false);
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

		/*Minecraft (allegedly uses 26 bits for X / Z and 12 for Y, perfect for packing into a 64 bit int*/
		int PackPosition(int x, int y, int z)
		{
			//Shift by amount

			const int64_t X = x & ((1LL << 26) - 1);
			const int64_t Y = y & ((1LL << 12) - 1);
			const int64_t Z = z & ((1LL << 26) - 1);

			return (X << (12 + 26) | (Y << 26) | Z);
		}

		void UnpackPosition(int Packed, int& OutX, int& OutY, int& OutZ)
		{
			//Unshift by amount
			OutZ = static_cast<int>(Packed & ((1LL << 26) - 1));
			OutY = static_cast<int>(Packed >> 26 & ((1LL << 12) - 1));
			OutX = static_cast<int>(Packed >> 12 + 26 & ((1LL << 26) - 1));

			//Signs
			if (OutX >= (1 << (26 - 1)))
				OutX -= (1 << 26);
			if (OutY >= (1 << (12 - 1)))
				OutY -= (1 << 12);
			if (OutZ >= (1 << (26 - 1)))
				OutZ -= (1 << 26);

		}

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