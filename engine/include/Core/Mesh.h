#pragma once

#include "pch.h" 

/*
* We are doing something rendering the naive way and IF we have time (we will not) we can go back and make it fancy...
*/

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>


namespace Crumb
{
	//TODO MAYBE RENAME TO BLOCK?

	/*
	* Meshes are the shapes that take up the world...
	*/
	class Mesh
	{
	public:

		Mesh();
		~Mesh();

		glm::vec3 m_WorldPosition; /*World Position this mesh is in*/

		/*Hard coded cube verticies data (relative)*/
		float* m_BlockVertData;


        /*This data is filled in from https://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/ */

		/*The actual vertex buffer*/
		unsigned int m_BlockVertBuffer;
        unsigned int m_VertArrayID;

		void Render();

		//We are not gonna need to worry abt rotation / scale FOR NOW, maybe if we do other meshes other than just blocks but in the current timescale its not looking likely...

		glm::mat4 GetWorldMat();

	};


}