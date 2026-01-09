#include "World/Chunk.h"

#include "glm/glm.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Crumb
{
	FChunk::FChunk()
	{
		m_VertArrayID = 0;

		//Think we still only need to do this once?
		glGenVertexArrays(1, &m_VertArrayID);

		glBindVertexArray(m_VertArrayID);

		glGenBuffers(1, &m_ChunkVertBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_ChunkVertBuffer);
		
		glGenBuffers(1, &m_ChunkIndBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ChunkIndBuffer);

		//This works for CHUNK COORDINATES as the sign bit is not needed - coords range 0-ChunkSize with 0 being bottom left (*** MIGHT HAVE CHANGED IN IMPLEM AND NOT UPDATED COMMENTS)
		m_WorldPos = { 0.f,0.f,0.f }; //Init pos to 0 0 0 
		m_FaceCount = 0;
		//Init the chunk as all air by default
		for (int i = 0; i < sizeof(ChunkBlocks) / sizeof(ChunkBlocks[0]); ++i)
			ChunkBlocks[i] = 1; //TEMP TODO FOR THE TIME BEING WE ARE SETTING IT ALL TO DIRT TO SEE BLOCKS RENDERING CORRECTLY...
	}

	void FChunk::CreateChunkMesh()
	{
		m_FaceCount = 0;

		//Is there a better way to do this than thiss?

		Verts = {};
		Indices = {};
		//Feels wasteful

		//We are just gonna do naively what minecraft does - put all the cube faces in one mesh, and skipping if the face's neighbour is not air...

		//Double nested for loop urgh
		for (int x = 0; x < 16; ++x)
			for (int y = 0; y < 16; ++y)
				for (int z = 0; z < 16; ++z)
				{

					unsigned char B = ChunkBlocks[GetBlockIndex(x,y,z)];
					if (B == 0) //Air, skip
						continue;

					//Use this to keep a record of the faces we need to add
					unsigned char Faces[6] = { 0,0,0,0,0,0 };
											//+X, -X, +Y, -Y, +Z, -Z


					if (x >= 15) //X edge, dont know whats in the next chunk, need the +X face
						Faces[0] = 1;
					else if (x <= 0) //X edge, dont know whats in the next chunk, need the -X face
						Faces[1] = 1;

					if (y >= 15) //Y edge, dont know whats in the next chunk, need the +Y face
						Faces[2] = 1;
					else if (y <= 0) //Y edge, dont know whats in the next chunk, need the -Y face
						Faces[3] = 1;

					if (z >= 15) //Z edge, dont know whats in the next chunk, need the +Z face
						Faces[4] = 1;
					else if (z <= 0) //Z edge, dont know whats in the next chunk, need the -Z face
						Faces[5] = 1;

					//neighbour time
					//Each face of this cube - if the touching block is air, then draw, else continue

					if (ChunkBlocks[GetBlockIndex(x+1, y, z)] == 0)
						Faces[0] = 1;
					if (ChunkBlocks[GetBlockIndex(x-1, y, z)] == 0)
						Faces[1] = 1;

					if (ChunkBlocks[GetBlockIndex(x, y+1, z)] == 0)
						Faces[2] = 1;
					if (ChunkBlocks[GetBlockIndex(x, y-1, z)] == 0)
						Faces[3] = 1;

					if (ChunkBlocks[GetBlockIndex(x, y, z+1)] == 0)
						Faces[4] = 1;
					if (ChunkBlocks[GetBlockIndex(x, y, z-1)] == 0)
						Faces[5] = 1;

					//At this point we will know what faces we want to render, now we just need to add these faces to the VBO/VAO/VEO

					if (Faces[0] == 1)
					{
						Verts.push_back({ x + 1, y,   z + 1 });
						Verts.push_back({ x + 1, y,   z });
						Verts.push_back({ x + 1, y + 1, z });
						Verts.push_back({ x + 1, y + 1, z + 1 });

						AddIndexes();
					}
					if (Faces[1] == 1)
					{
						Verts.push_back({ x, y, z + 1 });
						Verts.push_back({ x, y, z });
						Verts.push_back({ x, y + 1, z });
						Verts.push_back({ x, y + 1, z + 1 });

						AddIndexes();
					}

					if (Faces[2] == 1)
					{
						Verts.push_back({ x,   y + 1, z + 1 });
						Verts.push_back({ x + 1, y + 1, z + 1 });
						Verts.push_back({ x + 1, y + 1, z });
						Verts.push_back({ x,   y + 1, z });

						AddIndexes();
					}
					if (Faces[3] == 1)
					{
						Verts.push_back({ x,   y, z });
						Verts.push_back({ x + 1, y, z });
						Verts.push_back({ x + 1, y, z + 1 });
						Verts.push_back({ x,   y, z + 1 });

						AddIndexes();
					}
						
					if (Faces[4] == 1)
					{
						Verts.push_back({ x, y,  z + 1 });
						Verts.push_back({ x + 1, y,  z + 1 });
						Verts.push_back({ x + 1, y + 1,  z + 1 });
						Verts.push_back({ x, y + 1,  z + 1 });

						AddIndexes();
					}
					if (Faces[5] == 1)
					{
						Verts.push_back({ x, y,  z });
						Verts.push_back({ x + 1, y,  z });
						Verts.push_back({ x + 1, y + 1,  z });
						Verts.push_back({ x, y + 1,  z });

						AddIndexes();
					}
				
				}

		//Updating OpenGL stuff

		//VBO (Vertex buffer)
		glBufferData(
			GL_ARRAY_BUFFER,
			Verts.size() * sizeof(glm::vec3),
			Verts.data(),
			GL_STATIC_DRAW
		);

		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER, 
			Indices.size() * sizeof(unsigned int),
			Indices.data(),
			GL_STATIC_DRAW
		);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(
			0, 3, GL_FLOAT, GL_FALSE,
			sizeof(glm::vec3),
			(void*)0
		);

		glBindVertexArray(0);
	}

	void FChunk::AddIndexes()
	{
		uint32_t FaceCount = static_cast<uint32_t>(Verts.size()) - 4;

		Indices.push_back(FaceCount + 0);
		Indices.push_back(FaceCount + 1);
		Indices.push_back(FaceCount + 2);
		Indices.push_back(FaceCount + 2);
		Indices.push_back(FaceCount + 3);
		Indices.push_back(FaceCount + 0);

	}

	glm::mat4 FChunk::GetWorldMat()
	{
		return glm::translate(glm::mat4(1.f), m_WorldPos);
	}


	void FChunk::RenderChunk()
	{
		glBindVertexArray(m_VertArrayID);
		glDrawElements(
			GL_TRIANGLES,
			Indices.size(),
			GL_UNSIGNED_INT,
			nullptr
		);

	}
}