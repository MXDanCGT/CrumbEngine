#pragma once

#include "pch.h"


namespace Crumb
{
/**
* We want to use memory pool for our "blocks" that are rendered...
*	https://dev.to/pigeoncodeur/optimizing-c-memory-management-with-a-custom-memory-pool-1o3b
*	^ referenced
* 
* 
*	https://medium.com/@threehappyer/memory-pool-techniques-in-c-79e01f6d2b19
*	^ referenced
*/

	template<typename T>
	class MemChunk
	{
	public:

		MemChunk(size_t ChunkCount)
		{
			m_ChunkCount = ChunkCount;

			for (size_t i = 0; i < m_ChunkCount; ++i)
				m_FreeChunks.push_back(new T);
		}

		~MemChunk() 
		{
			for (auto i : m_FreeChunks)
			{
				delete i;
			}
		}

		T* allocate()
		{
			//IF I COME BACK AND MULTITHREAD I WILL NEED TO MUTEX HERE

			//Bad alloc :(
			assert(!m_FreeChunks.empty());

			T* Chunk = m_FreeChunks.back();
			m_FreeChunks.pop_back();
			return Chunk;
		}

		void deallocate(T* OldChunk)
		{
			//IF I COME BACK AND MULTITHREAD I WILL NEED TO MUTEX HERE
			m_FreeChunks.push_back(static_cast<T*>(OldChunk));
		}

		size_t m_ChunkCount; /*How many chunks are we pooling?*/

		/*The free chunks we have available to use*/
		std::vector<T*> m_FreeChunks;
	};

}