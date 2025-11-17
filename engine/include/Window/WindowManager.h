#pragma once
#include "pch.h"


//FORWARD DECLS

struct GLFWwindow;
struct GLFWmonitor;

namespace Crumb {

	class MInputManager;

	/*
	* Window manager handles creation and maintenance of the window used in the game / engine
	* Interface for lower level code...
	*/
	class MWindowManager 
	{

	public:

		MWindowManager(int WindowWidth, int WindowHeight, std::string WindowName, std::shared_ptr<MInputManager> InputManager, bool Fullscreen = false); /*Specific dims window*/

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


		/*Weak ptr to our input manager, allows us to see the events with key bindings and add them to the managers event queue*/
		std::weak_ptr<MInputManager> m_InputManager;
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

		MWindowManager_GLFW(int WindowWidth, int WindowHeight, std::string WindowName, std::shared_ptr<MInputManager> InputManager, bool Fullscreen = false);
		virtual ~MWindowManager_GLFW();

		/*Initialise our main window with GLFW*/
		virtual int InitWindow() override;

		/*Update the window GLFW implementation*/
		virtual void UpdateWindow() override;

		/*GLFW keypress callback function - accesses input manager, and bindings as defined by the application programmer*/
		static void ManageInput(GLFWwindow* window, int key, int scancode, int action, int mods);

		/*Get whether or not the game window should stay open - used in game loop running*/
		virtual bool bShouldCloseWindow() override;

		/*Shutdown the window(s)*/
		virtual void Shutdown() override;

	private:

		/*MEMBER VARIABLES*/

		/*
		* GLFW was written in C, and theres some fiddling with custom constructors and destructors I need to do to make unique ptrs of these types
		* For the time being we will just be careful to always delete these!
		*/

		/*GLFW window ptr for the main game screen*/
		GLFWwindow* m_Window; //NTS: Make sure all the window ptrs are called the same thing

		/*GLFW monitor ptr for where we put those windows*/
		GLFWmonitor* m_Monitor;
	};
}