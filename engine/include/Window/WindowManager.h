#pragma once
#include "pch.h"

struct GLFWwindow; //Forward decl

namespace Crumb {

	/*
	* Window manager handles creation and maintenance of the window used in the game / engine
	* Interface for lower level code...
	*/
	class MWindowManager 
	{

	public:

		MWindowManager(int WindowWidth, int WindowHeight, std::string WindowName, bool Fullscreen = false); /*Specific dims window*/
		~MWindowManager();

		virtual int InitWindow() = 0;

		/*Update window, poll window events*/
		virtual void UpdateWindow() = 0;

		/*Helper function to get if the window should close i.e.: if we should stop the game loop*/
		virtual bool bShouldCloseWindow() = 0; 

		/*Shutdown the window*/
		virtual void Shutdown() = 0;

	protected:

		/*MEMBER VARIABLES*/

		int m_WindowWidth;
		int m_WindowHeight;

		bool m_Fullscreen;

		std::string m_WindowName;
		

	};

	/*
	* IMPLEMENTATIONS OF DIFFERENT LIBS FOR PLATFORMS
	*/

	/*
	* Window implementation for GLFW
	*/
	class MWindowManager_GLFW : public MWindowManager
	{
	public:

		MWindowManager_GLFW(int WindowWidth, int WindowHeight, std::string WindowName, bool AutoInit);
		~MWindowManager_GLFW();

		virtual int InitWindow() override;

		virtual void UpdateWindow() override;

		virtual bool bShouldCloseWindow() override;

		virtual void Shutdown() override;
	private:

		/*MEMBER VARIABLES*/

		GLFWwindow* m_Window; //NTS: Make sure all the window ptrs are called the same thing
	};
}