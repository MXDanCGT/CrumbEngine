#pragma once

#include <memory>
#include <string>

struct GLFWwindow; 

namespace Crumb {

	/*
	* Window manager handles creation and maintenance of the window used in the game / engine
	* Interface for lower level code...
	*/

	class MWindowManager 
	{
	public:

		~MWindowManager();
		MWindowManager(int ScreenWidth, int ScreenHeight, std::string WindowName);


		int InitWindow();

	private:

		int m_ScreenWidth;
		int m_ScreenHeight;

		std::string m_WindowName;
		
		
		GLFWwindow* m_Window;
	};

}