#pragma once

#include "pch.h" 

/*
* We are doing something rendering the naive way and IF we have time (we will not) we can go back and make it fancy...
*/




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

		/*Hard coded cube verticies positions*/
		float* BlockVertData;


        /*This data is filled in from https://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/ */

		/*The actual vertex buffer*/
		unsigned int BlockVertBuffer;
        unsigned int VertArrayID;

		void Render();
	};


}