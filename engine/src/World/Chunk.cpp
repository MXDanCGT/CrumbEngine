#include "World/Chunk.h"

#include "glm/glm.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Crumb
{
	FChunk::FChunk()
	{
		m_VertArrayID = 0;
		Tex = new Texture_GL("resources/Blocks.bmp");

		//Think we still only need to do this once?
		glGenVertexArrays(1, &m_VertArrayID);
		glBindVertexArray(m_VertArrayID);	

		//Gen vert buffer
		glGenBuffers(1, &m_ChunkVertBuffer);
		glGenBuffers(1, &m_ChunkIndBuffer);
		
		glBindBuffer(GL_ARRAY_BUFFER, m_ChunkVertBuffer);
		//Data empty initially...

		//Positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			sizeof(FVert),
			(void*)offsetof(FVert, Pos)
		);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ChunkIndBuffer);

		//UVs
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(
			1, 
			2, 
			GL_FLOAT, 
			GL_FALSE, 
			sizeof(FVert), 
			(void*)offsetof(FVert, UV)
		);
		//Dont believe I need to set this up more than once ^^^

		glBindVertexArray(0);

		//This works for CHUNK COORDINATES as the sign bit is not needed - coords range 0-ChunkSize with 0 being bottom left (*** MIGHT HAVE CHANGED IN IMPLEM AND NOT UPDATED COMMENTS)
		m_WorldPos = { 0.f,0.f,0.f }; //Init pos to 0 0 0 
		m_FaceCount = 0;
		//Init the chunk as all air by default


		//MORE ROBUST CHUNK CHECKER
		for (int i = 0; i < sizeof(ChunkBlocks) / sizeof(ChunkBlocks[0]); ++i)
			if (i % 2 == 0)
				ChunkBlocks[i] = 1; //TEMP TODO FOR THE TIME BEING WE ARE SETTING IT ALL TO DIRT TO SEE BLOCKS RENDERING CORRECTLY...
			else
				ChunkBlocks[i] = 0;
	}

	void FChunk::CreateChunkMesh()
	{
		m_FaceCount = 0;

		//Is there a better way to do this than thiss?

		Verts.clear();
		Indices.clear();
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

					if (ChunkBlocks[GetBlockIndex(x+1, y, z)] == 0) //If +x neighbour is an air block
						Faces[0] = 1;
					if (ChunkBlocks[GetBlockIndex(x-1, y, z)] == 0) //If -x neighbour is an air block
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

					//I KNOW THE BUG
					//Before we were using the exact same order of verts in both +/- faces, only changing the offset but WE NEED to reverse em!


					//

					// 0             1
					// ---------------
					//|               |
					//|               |
					//|               |
					//|               |
					//|               |
					//----------------
					//3				  2

					//Faces "front" wants to be in said direction

					//UVS layed out like this:
					// ------
					// | X	|
					// |XXXX|  In each individual "section" of the texture atlas - we will offset these UVs in the shader by the correct amount
					// | X	|
					// |	|
					// ------

					//The UVS will be offset by a set amount based on our block type...

					//We are just gonna offset the UVs here...
					float AtlasSize = 1.f / 2.f; //UPDATE WHEN INCREASING BLOCKS SIZE, TODO EXPOSE TO USER
					glm::vec2 UVOffset(0.f, 0.f);
					switch (B)
					{
					case 2:
						UVOffset[0] = 0.5;
						break;
					}

					//Also I spaced these all out correctly but whenever I finish a line visual studio takes the wheel and unalligns it so unsure if ill be arsed to fix that again
					if (Faces[0] == 1) //+X
					{
						Verts.push_back(FVert({ x + 1, y + 1, z },		 UVOffset + (glm::vec2(0.f,	 0.25f)  * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y + 1, z + 1 },   UVOffset + (glm::vec2(0.25f, 0.25f)  * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y,		z + 1 }, UVOffset + (glm::vec2(0.25f, 0.5f)   * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y,		z },	 UVOffset + (glm::vec2(0.f,   0.5f)   * AtlasSize)));

						AddIndexes();
					}
					if (Faces[1] == 1) //-X - same as +x, reversed and at x coord not x + 1...
					{
						Verts.push_back(FVert({ x, y,	  z },	   UVOffset + (glm::vec2(0.5f,  0.25f) * AtlasSize)));
						Verts.push_back(FVert({ x, y,	  z + 1 }, UVOffset + (glm::vec2(0.75f, 0.25f) * AtlasSize)));
						Verts.push_back(FVert({ x, y + 1, z + 1 }, UVOffset + (glm::vec2(0.75f, 0.5f)  * AtlasSize)));
						Verts.push_back(FVert({ x, y + 1, z },	   UVOffset + (glm::vec2(0.5f, 0.5f)   * AtlasSize)));

						AddIndexes();
					}

					if (Faces[2] == 1) //+y
					{
						Verts.push_back(FVert({ x,	 y + 1, z + 1 },   UVOffset + (glm::vec2(0.25f, 0.f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y + 1, z + 1 }, UVOffset + (glm::vec2(0.5f, 0.f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y + 1, z },	   UVOffset + (glm::vec2(0.5f, 0.25f) * AtlasSize)));
						Verts.push_back(FVert({ x,	 y + 1, z },	   UVOffset + (glm::vec2(0.25f, 0.25f) * AtlasSize)));

						AddIndexes();
					}
					if (Faces[3] == 1) //-y
					{
						Verts.push_back(FVert({ x,	 y, z },       UVOffset + (glm::vec2(0.25f, 0.5f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y, z },     UVOffset + (glm::vec2(0.5f, 0.5f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y, z + 1 }, UVOffset + (glm::vec2(0.5f, 0.75f) * AtlasSize)));
						Verts.push_back(FVert({ x,     y, z + 1 }, UVOffset + (glm::vec2(0.25f, 0.75f) * AtlasSize)));

						AddIndexes();
					}
						
					if (Faces[4] == 1) //+z
					{
						Verts.push_back(FVert({ x,     y,     z + 1 },	 UVOffset + (glm::vec2(0.25f, 0.25f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y,		z + 1 }, UVOffset + (glm::vec2( 0.5f,  0.25f ) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y + 1, z + 1 },	 UVOffset + (glm::vec2( 0.5f,  0.5f ) * AtlasSize)));
						Verts.push_back(FVert({ x,     y + 1, z + 1 },   UVOffset + (glm::vec2( 0.25f, 0.5f ) * AtlasSize)));

						AddIndexes();
					}
					if (Faces[5] == 1) //-z
					{
						Verts.push_back(FVert({ x,     y + 1, z },   UVOffset + (glm::vec2(0.75f, 0.25f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y + 1, z },	 UVOffset + (glm::vec2(1.f, 0.25f) * AtlasSize)));
						Verts.push_back(FVert({ x + 1, y,		z }, UVOffset + (glm::vec2(1.f, 0.5f) * AtlasSize)));
						Verts.push_back(FVert({ x,     y,     z },	 UVOffset + (glm::vec2(0.75f,0.5f) * AtlasSize)));

						AddIndexes();
					}
				
				}

		//Updating OpenGL stuff

		//Texture!


		glBindVertexArray(m_VertArrayID);

		//VBO (Vertex buffer)
		glBindBuffer(GL_ARRAY_BUFFER, m_ChunkVertBuffer);
		glBufferData(
			GL_ARRAY_BUFFER,
			Verts.size() * sizeof(FVert),
			Verts.data(),
			GL_DYNAMIC_DRAW
		);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ChunkIndBuffer);
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER, 
			Indices.size() * sizeof(unsigned int),
			Indices.data(),
			GL_DYNAMIC_DRAW
		);
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
		glBindVertexArray(0);
	}
}