#pragma once
#include "pch.h"

#include "Platform.h"
#include "Window/WindowManager.h"
#include "Input/InputManager.h"
#include "World/World.h"
#include "Core/Camera.h"

namespace Crumb
{

	/*Game is the actual app being run - the application programmer will extend this to begin adding their own implementation*/
	class Game
	{
	public:

		Game(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen = false); 
		~Game();

		/*Game objects initialisation*/
		virtual int Init();

		/**
		*Function called once every game frame
		* 
		* Base implementation handles updating the systems that the A.P wont touch & ECS games systems
		*/
		virtual void Tick(float DeltaTime);

		/*EOL*/
		virtual void Shutdown();

		/*GETTERS AND SETTERS*/
		inline FPlatformSettings GetPlatformSettings() const { return m_PlatformSettings; }
		inline void SetPlatformSettings(FPlatformSettings GivenSettings) { m_PlatformSettings = GivenSettings; }

		/*Should we continue to run the game, or close (for whatever reason)*/
		bool ShouldCloseGame();

	protected:

		FPlatformSettings m_PlatformSettings;

		std::unique_ptr<MWindowManager> m_WindowManager;

		/*shared ptr so we can pass a weak ptr to the window manager... ?*/
		MInputManager* m_InputManager;

		/*The game world*/
		std::unique_ptr<World> m_World;

		/*All games have a camera - TODO APP PROG CAN OVERRIDE THIS*/
		std::unique_ptr<Camera> m_MainCamera;

	};

}