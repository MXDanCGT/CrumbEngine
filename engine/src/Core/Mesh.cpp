#include "Core/Mesh.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{

	Mesh::Mesh()
	{
		glGenVertexArrays(1, &VertArrayID);

		glBindVertexArray(VertArrayID);

		BlockVertData = new GLfloat[]
        {
            1.0f,-1.0f,-1.0f, // triangle 1 : begin
           -1.0f,-1.0f, 1.0f,
           -1.0f, 1.0f, 1.0f, // triangle 1 : end
            1.0f, 1.0f,-1.0f, // triangle 2 : begin
           -1.0f,-1.0f,-1.0f,
           -1.0f, 1.0f,-1.0f, // triangle 2 : end
            1.0f,-1.0f, 1.0f,
           -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
           -1.0f,-1.0f,-1.0f,
           -1.0f,-1.0f,-1.0f,
           -1.0f, 1.0f, 1.0f,
           -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
           -1.0f,-1.0f, 1.0f,
           -1.0f,-1.0f,-1.0f,
           -1.0f, 1.0f, 1.0f,
           -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
           -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
           -1.0f, 1.0f,-1.0f,
           -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
           -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
        };

        glGenBuffers(1, &BlockVertBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, BlockVertBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(BlockVertData), BlockVertData, GL_STATIC_DRAW);
	}

    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &BlockVertBuffer);
        glDeleteVertexArrays(1, &VertArrayID);
    }

    void Mesh::Render()
    {
        glBindVertexArray(VertArrayID);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

    }
}