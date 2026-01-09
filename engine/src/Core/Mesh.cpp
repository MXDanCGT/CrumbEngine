#include "Core/Mesh.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{

	Mesh::Mesh()
	{

        m_WorldPosition = {0.f, 0.f, 0.f};

		glGenVertexArrays(1, &m_VertArrayID);

		glBindVertexArray(m_VertArrayID);

		m_BlockVertData = new float[108]
        {
            1.0f, -1.0f,-1.0f, // triangle 1 : begin
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

        glGenBuffers(1, &m_BlockVertBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_BlockVertBuffer);
        glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), m_BlockVertData, GL_STATIC_DRAW);
	}

    Mesh::~Mesh()
    {
        delete[] m_BlockVertData;

        glDeleteBuffers(1, &m_BlockVertBuffer);
        glDeleteVertexArrays(1, &m_VertArrayID);
    }

    void Mesh::Render()
    {
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, m_BlockVertBuffer);
        glVertexAttribPointer(0,
            3,
            GL_FLOAT,
            GL_FALSE,
            3 * sizeof(float),
            (void*)0
        );
        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
        glDisableVertexAttribArray(0);

    }

    glm::mat4 Mesh::GetWorldMat()
    {
        return glm::translate(glm::mat4(1.f), m_WorldPosition);
    }
}