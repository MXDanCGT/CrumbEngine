#include "Window/WindowManager.h"

#include <glad/glad.h> //WHY DOES IT WORK THIS WAY AROUND?
#include <GLFW/glfw3.h>

	
namespace Crumb
{

	MWindowManager::MWindowManager(int WindowWidth, int WindowHeight, std::string WindowName, bool Fullscreen)
	{
		m_WindowWidth = WindowWidth;
		m_WindowHeight = WindowHeight;
		m_WindowName = WindowName;

		m_Fullscreen = Fullscreen;
	}

	MWindowManager::~MWindowManager()
	{}

	MWindowManager_GLFW::MWindowManager_GLFW(int WindowWidth, int WindowHeight, std::string WindowName, bool FullScreen) : MWindowManager::MWindowManager(WindowWidth, WindowHeight, WindowName, FullScreen)
	{
		m_Window = nullptr;
	}

	MWindowManager_GLFW::~MWindowManager_GLFW()
	{
	}

	int MWindowManager_GLFW::InitWindow()
	{
		assert(glfwInit());
		if (!m_Fullscreen)
			m_Window = glfwCreateWindow(800, 600, m_WindowName.c_str(), NULL, NULL);
		else
			m_Window = glfwCreateWindow(800, 600, m_WindowName.c_str(), glfwGetPrimaryMonitor(), NULL);

		if (!m_Window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(m_Window);

		assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); 

		return 0;
	}

	void MWindowManager_GLFW::UpdateWindow()
	{
		while(!glfwWindowShouldClose(m_Window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
	}

	bool MWindowManager_GLFW::bShouldCloseWindow()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void MWindowManager_GLFW::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

}
