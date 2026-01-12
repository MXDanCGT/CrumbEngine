#include "Window/WindowManager.h"

#include "Input/InputManager.h"
#include "Renderer/Renderer.h"
#include "Core/Camera.h"
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
		//m_InputManager = InputManager;
	}

	MWindowManager_GLFW::MWindowManager_GLFW(int WindowWidth, int WindowHeight, std::string WindowName, MInputManager* InputManager, bool Fullscreen) : MWindowManager::MWindowManager(WindowWidth, WindowHeight, WindowName, InputManager, Fullscreen)
	{
		m_Window = nullptr;
		m_Monitor = nullptr;

		//m_InputManager = (MInputManager_GLFW*)InputManager;
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
		
		//glfwSetWindowUserPointer(m_Window, (void*)m_InputManager);
		double X;
		double Y;
		glfwGetCursorPos(m_Window, &X, &Y);
		m_MousePosition = new double[2] {X, Y};

		glfwSetKeyCallback(m_Window, ManageKeyboardInput);
		glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //Dont want to actually see the mouse
		glfwSetMouseButtonCallback(m_Window, ManageMouseInput); //Essentially same as the keyboard input
		glfwSetCursorPosCallback(m_Window, ManageMouseMovement);

		glfwMakeContextCurrent(m_Window);

		glfwSetFramebufferSizeCallback(m_Window, SizeCallback);

		MInputManager_GLFW* Test = (MInputManager_GLFW*)glfwGetWindowUserPointer(m_Window);

		return 0;
	}

	void MWindowManager_GLFW::SizeCallback(GLFWwindow* Win, int Width, int Height)
	{
		glViewport(0, 0, Width, Height);
	}

	void MWindowManager_GLFW::ManageKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//Overwrite the state our input system is currently reading with a new one...
		WindowInputs_Keys.KeyStates[key] = action; //Overwrite with the new state...

	
	}

	void MWindowManager_GLFW::ManageMouseMovement(GLFWwindow* window, double XPos, double YPos)
	{
		//We want to get a float value for the mouse movement...

		//REMEMBER WE SAID CRUMB X =  500, CRUMB Y = 501...
		WindowInputs_Axis.AxisStates[500] = XPos - m_MousePosition[0];
		WindowInputs_Axis.AxisStates[501] = YPos - m_MousePosition[1];

	}

	void MWindowManager_GLFW::ManageMouseInput(GLFWwindow* window, int button, int action, int mods)
	{
		WindowInputs_Keys.KeyStates[button] = action; //Should work fine here too
	}

	void MWindowManager_GLFW::UpdateWindow()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//double* StupidFuckingTemp = new double[2] {0.f, 0.f};
		glfwGetCursorPos(m_Window, &m_MousePosition[0], &m_MousePosition[1]);



	}

	void MWindowManager_GLFW::PostRender()
	{
		//Whoopsies, input updates happen AFTER update window so resetting these wouldve broke everything
		//TODO NEED TO FIGURE OUT IF ALL AXIS MAPPINGS NEED TO BE RESET OR JUST MOUSE MOVEMENT
		WindowInputs_Axis.AxisStates[500] = 0.f;
		WindowInputs_Axis.AxisStates[501] = 0.f;
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
