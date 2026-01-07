#include "Window/WindowManager.h"

#include "Input/InputManager.h"
#include "Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

	
namespace Crumb
{
	MWindowManager::MWindowManager(int WindowWidth, int WindowHeight, std::string WindowName, MInputManager* InputManager, bool Fullscreen)
	{
		m_WindowWidth = WindowWidth;
		m_WindowHeight = WindowHeight;
		m_WindowName = WindowName;

		m_Fullscreen = Fullscreen;

		m_InputManager = InputManager;

	}

	MWindowManager_GLFW::MWindowManager_GLFW(int WindowWidth, int WindowHeight, std::string WindowName, MInputManager* InputManager, bool Fullscreen) : MWindowManager::MWindowManager(WindowWidth, WindowHeight, WindowName, InputManager, Fullscreen)
	{
		m_Window = nullptr;
		m_Monitor = nullptr;

		m_InputManager = (MInputManager_GLFW*)InputManager;
	}

	MWindowManager_GLFW::~MWindowManager_GLFW()
	{
		delete m_Window;
		delete m_Monitor;
	}

	int MWindowManager_GLFW::InitWindow()
	{
		assert(glfwInit()); //Make sure glfw inits correctly to go past this point...

		m_Monitor = glfwGetPrimaryMonitor();

		if (!m_Fullscreen)
			m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL);
		else
		{
			//Windowed fullscreen not real fullscreen
			//TODO more than just binary init options

			const GLFWvidmode* VidMode = glfwGetVideoMode(m_Monitor);
			
			glfwWindowHint(GLFW_RED_BITS, VidMode->redBits); //I will be perfectly honest with you I havent a fucking clue what these 4 lines do, its just in the GLFW bootstrap on the website
			glfwWindowHint(GLFW_GREEN_BITS, VidMode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, VidMode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, VidMode->refreshRate);

			m_Window = glfwCreateWindow(VidMode->width, VidMode->height, m_WindowName.c_str(), m_Monitor, NULL);
		}
		if (!m_Window)
		{
			glfwTerminate();
			return -1;
		}
		
		glfwSetWindowUserPointer(m_Window, (void*)m_InputManager);

		glfwSetKeyCallback(m_Window, ManageInput);

		glfwMakeContextCurrent(m_Window);
		MInputManager_GLFW* Test = (MInputManager_GLFW*)glfwGetWindowUserPointer(m_Window);

		assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); 
	
		return 0;
	}

	void MWindowManager_GLFW::ManageInput(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//FROM HERE
		//We want to take this key and see if it matches any input key bindings in our input manager
		//If so add to input event queue TODO this feels a little dodgy going back and forth between systems like this..

		//Circumvents need for static shit
		MInputManager_GLFW* InputManager = nullptr;
		InputManager = (MInputManager_GLFW*)glfwGetWindowUserPointer(window);

		//As Crumb key numbers are the same as GLFW, we just need to find a binding in the Input manager for this number...

		//And this function is only called when there IS a key input event, so we dont need to filter that.
		//Simply pass off the key and action values


		if(InputManager)
			InputManager->LogInputEvent(key, action, mods);
	}

	void MWindowManager_GLFW::UpdateWindow()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//m_Renderer->Update();
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
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
