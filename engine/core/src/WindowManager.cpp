#include "WindowManager.h"

namespace Crumb
{

	MWindowManager::MWindowManager(int ScreenWidth, int ScreenHeight, std::string WindowName)
	{
		m_ScreenWidth = ScreenWidth;
		m_ScreenHeight = ScreenHeight;
		m_WindowName = WindowName;
		m_Window = nullptr;
	}

	MWindowManager::~MWindowManager()
	{
	}

	int MWindowManager::InitWindow()
	{
		printf("Foo!\n");

		//SetWindow(std::make_unique<GLFWwindow>(glfwCreateWindow(GetScreenWidth(), GetScreenHeight(), GetWindowName, NULL, NULL)));

		//if (!GetWindow())
		//	return -1;

		//glfwMakeContextCurrent(GetWindow());

		//while(!glfwWindowShouldClose(GetWindow()))
		//{
		//	glClear(GL_COLOR_BUFFER_BIT);
		//	glfwSwapBuffers(GetWindow());
		//	glfwPollEvents();
		//}

		//glfwTerminate();
		//return 0;

		return 0;
	}

}