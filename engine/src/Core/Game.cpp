#include "Core/Game.h"

#include "World/Chunk.h"

#include "ecs.hpp/ecs.hpp"
#include "Core/BaseSystem.h"

#include "Input/InputSystem.h"

using namespace ecs_hpp;

namespace Crumb
{
	Game::Game(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen)
	{
		switch (m_PlatformSettings.WindowPlatform)
		{
		case EPS_Window::EPS_W_GLFW: //GLFW window
			//m_InputManager = new MInputManager_GLFW();
			m_WindowManager = std::make_unique<MWindowManager_GLFW>(ScreenHeight, ScreenWidth, WindowName, nullptr, Fullscreen);

			//We also wanna make our renderer GL
			m_Renderer = std::make_unique<MRenderer_GL>(); //ENSURING WE ARE CALLING THIS

			break;

		default:
			//m_InputManager = new MInputManager_GLFW();
			m_WindowManager = std::make_unique<MWindowManager_GLFW>(ScreenHeight, ScreenWidth, WindowName, nullptr, Fullscreen);
			break;
		}

		//World must only be constructed on Init, after window has been init!


		m_MainCamera = std::make_unique<Camera>();


		m_GameRegistry.assign_feature<FInputFeature>().add_system<InputSystem>();

		printf("Game object initialised\n");
	}

	Game::~Game()
	{
		m_WindowManager->Shutdown();

	}

	int Game::Init()
	{
		if (m_WindowManager->InitWindow() != 0)
			return -1;


		m_Renderer->Init();


		//If we define a world in OUR implementation
		if(m_World)
			m_World->GenerateWorld();

		return 0;
	}

	bool Game::ShouldCloseGame()
	{
		return m_WindowManager->bShouldCloseWindow();
	}

	void Game::Shutdown()
	{
		m_WindowManager->Shutdown();
	}

	void Game::Tick(float DeltaTime)
	{

		//This being called means we've already handled whether or not the app should close...

		m_WindowManager->UpdateWindow(); 
		m_GameRegistry.process_event(FInputEvents{m_WindowManager->WindowInputs}); //Update our system based on our recieved inputs this frame
		m_GameRegistry.process_event(FGameplayEvent{DeltaTime});
		m_Renderer->Update(m_World->GetLoadedChunks(), m_MainCamera.get());
		m_WindowManager->PostRender(); //+ inputs handled here...



		//Go through our event queue and do it
	}
}