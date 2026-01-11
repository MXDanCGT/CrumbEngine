#pragma once

namespace Crumb
{
	//Was following this tutorial for a lot of the file loading stuff... https://mylearningspace.abertay.ac.uk/d2l/le/content/37645/viewContent/940258/View

	struct FBMPFileData
	{
		//Metadata
		unsigned char header[54];
		unsigned int DataPos;
		unsigned int Width, Height;
		unsigned int ImageSize;

		//Actual RGB data
		unsigned char* Data;
	};
	//Given up on this shite, just using STB IMAGE

	struct FSTBFileData
	{
		unsigned char* Data;
		int Width;
		int Height;
		int nrChannels;
	};

	/*Base crumb texture class, handles loading and streaming of a texture / png resource*/
	class Texture
	{
	public:

		Texture();
		Texture(const char* Filename); /*Constructor overload auto init with the specified file...*/

		virtual bool Initialise(const char* Filename) = 0;
		virtual bool Shutdown() = 0;

		bool m_bTexLoaded;
	};


	/*OpenGL implementation of texture*/
	class Texture_GL : public Texture
	{
	public:

		Texture_GL();
		Texture_GL(const char* Filename);


		virtual bool Initialise(const char* Filename) override;
		virtual bool Shutdown() override;


		FBMPFileData LoadBMP_GL(const char* ImgPath);

		FSTBFileData STBLoadImage(const char* Filepath);

		unsigned int m_TexID;
	};
}