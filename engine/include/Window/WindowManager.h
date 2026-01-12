#pragma once
#include "pch.h"

#include "World/Chunk.h"
#include "Input/InputEvent.h"

//FORWARD DECLS

struct GLFWwindow;
struct GLFWmonitor;

namespace Crumb {

	class MInputManager;
	class MInputManager_GLFW;

	class MRenderer;
	class MRenderer_GL;

	class Camera;

	/*
	* Window manager handles creation and maintenance of the window used in the game / engine
	* Interface for lower level code...
	*/
	class MWindowManager 
	{

	public:
		MWindowManager(int WindowWidth, int WindowHeight, std::string WindowName, MInputManager* InputManager, bool Fullscreen = false); /*Specific dims window*/

		virtual int InitWindow() = 0;

		/*Update window, poll window events*/
		virtual void UpdateWindow() = 0;

		/*Post render update window handling*/
		virtual void PostRender() = 0;


		/*Helper function to get if the window should close i.e.: if we should stop the game loop*/
		virtual bool bShouldCloseWindow() = 0; 

		/*Shutdown the window*/
		virtual void Shutdown() = 0;


		inline static FKeyStateTracker WindowInputs;

	protected:

		/*MEMBER VARIABLES*/

		int m_WindowWidth;
		int m_WindowHeight;

		bool m_Fullscreen;

		std::string m_WindowName;

		/*Position of the mouse - set to whatever ur Window managers variation of get mouse position is on game start*/
		double* m_MousePosition;

	private:

		/*Weak ptr to our input manager, allows us to see the events with key bindings and add them to the managers event queue*/
		//MInputManager* m_InputManager;
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

		MWindowManager_GLFW(int WindowWidth, int WindowHeight, std::string WindowName, MInputManager* InputManager, bool Fullscreen = false);
		virtual ~MWindowManager_GLFW();

		/*Initialise our main window with GLFW*/
		virtual int InitWindow() override;

		/*Update the window GLFW implementation*/
		virtual void UpdateWindow() override;

		virtual void PostRender() override;

		/*GLFW keypress callback function - accesses input manager, and bindings as defined by the application programmer*/
		static void ManageKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);
		/*As above for mouse buttons*/
		static void ManageMouseInput(GLFWwindow* window, int button, int action, int mods);

		/*Managing mouse axis movement*/
		static void ManageMouseMovement(GLFWwindow* window, double XPos, double YPos);

		/*Get whether or not the game window should stay open - used in game loop running*/
		virtual bool bShouldCloseWindow() override;

		/*Shutdown the window(s)*/
		virtual void Shutdown() override;

		/*Simple resizing function...*/
		static void SizeCallback(GLFWwindow* Win, int Width, int Height);

		/*MEMBER VARIABLES*/

		/*
		* GLFW was written in C, and theres some fiddling with custom constructors and destructors I need to do to make unique ptrs of these types
		* For the time being we will just be careful to always delete these!
		*/

		/*GLFW window ptr for the main game screen*/
		GLFWwindow* m_Window; //NTS: Make sure all the window ptrs are called the same thing

		/*GLFW monitor ptr for where we put those windows*/
		GLFWmonitor* m_Monitor;

		//MInputManager_GLFW* m_InputManager;
	

		std::unique_ptr<MRenderer_GL> m_Renderer;


		

	};
}