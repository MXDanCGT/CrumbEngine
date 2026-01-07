#include "Core/Game.h"


namespace Crumb
{
	Game::Game(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen)
	{
		switch (m_PlatformSettings.WindowPlatform)
		{
		case EPS_Window::EPS_W_GLFW: //GLFW window
			m_InputManager = new MInputManager_GLFW();
			m_WindowManager = std::make_unique<MWindowManager_GLFW>(ScreenHeight, ScreenWidth, WindowName, m_InputManager, Fullscreen);
			break;

		default:
			m_InputManager = new MInputManager_GLFW();
			m_WindowManager = std::make_unique<MWindowManager_GLFW>(ScreenHeight, ScreenWidth, WindowName, m_InputManager, Fullscreen);
			break;
		}

		printf("Game object initialised\n");
	}

	Game::~Game()
	{

	}

	int Game::Init()
	{
		return 	m_WindowManager->InitWindow();;
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
		m_InputManager->Update();
		//Go through our event queue and do it
	}
}