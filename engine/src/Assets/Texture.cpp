#include "Assets/Texture.h"

#include "glm/glm.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//https://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/

namespace Crumb
{
	Texture::Texture()
	{
		m_bTexLoaded = false;
	}

	Texture::Texture(const char* Filename)
	{
		m_bTexLoaded = false;
	}


	Texture_GL::Texture_GL()
	{
		m_TexID = 0;
		m_bTexLoaded = false;
	}

	Texture_GL::Texture_GL(const char* Filename)
	{
		m_TexID = 0;
		m_bTexLoaded = false;
		Initialise(Filename);
		m_bTexLoaded = true;
	}


	bool Texture_GL::Initialise(const char* Filename)
	{

		FSTBFileData Out = STBLoadImage(Filename);

		glGenTextures(1, &m_TexID);
		glBindTexture(GL_TEXTURE_2D, m_TexID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // for minification
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // for magnification
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Out.Width, Out.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Out.Data);
		glGenerateMipmap(GL_TEXTURE_2D);

		return true;
	}

	bool Texture_GL::Shutdown()
	{
		return true; //TEMP
	}

	//My understanding of a BMP is that the first 54 bytes are header info then the rest of the file is the image itself
	FBMPFileData Texture_GL::LoadBMP_GL(const char* Filename)
	{
		//TODO SOMETHINGS NOT RIGHT
		FILE* TexFile = fopen(Filename, "rb");
		
		if (!TexFile) //Ensure the image exists
		{
			printf("Image couldn't be opened");
			assert(false);
		}

		FBMPFileData Dat;

		//Headers need to be 54 bytes                Needs to start "BM" as well
		if (fread(Dat.header, 1, 54, TexFile) != 54)
		{
			printf("Not a bmp file :(");
			assert(false);
		}

		if (Dat.header[0] != 'B' || Dat.header[1] != 'M')
		{
			printf("Not a bmp file :(");
			assert(false);
		}

		Dat.Width = *(int*)&(Dat.header[0x12]);
		Dat.Height = *(int*)&(Dat.header[0x16]);

		Dat.DataPos = *(int*)&(Dat.header[0x0A]);
		Dat.ImageSize = *(int*)&(Dat.header[0x22]);

		if (Dat.ImageSize == 0)    Dat.ImageSize = Dat.Width * Dat.Height * 3; // 3 : one byte for each Red, Green and Blue component
		if (Dat.DataPos == 0)      Dat.DataPos = 54;

		//TODO ADD THE MAKING UP MISSING INFO IT TALKS ABT IN THE TUTORIAL

		Dat.Data = new unsigned char[Dat.ImageSize];

		fread(Dat.Data, 1, Dat.ImageSize, TexFile);

		fclose(TexFile);

		printf("W=%d H=%d ImageSize=%d Expected=%d\n",
			Dat.Width,
			Dat.Height,
			Dat.ImageSize,
			Dat.Width * Dat.Height * 3
		);
		return Dat;

	}

	FSTBFileData Texture_GL::STBLoadImage(const char* Filepath)
	{
		FSTBFileData D;
		D.Data = stbi_load(Filepath, &D.Width, &D.Height, &D.nrChannels, 0);

		return D;
	}
}
