#include "Game/Game.h"


namespace Crumb
{
	Game::Game(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen)
	{

		switch (m_PlatformSettings.WindowPlatform)
		{
		case EPS_Window::EPS_W_GLFW: //GLFW window
			m_WindowManager = std::make_unique<MWindowManager_GLFW>(ScreenHeight, ScreenWidth, WindowName, Fullscreen);
			break;

		default:
			m_WindowManager = std::make_unique<MWindowManager_GLFW>(ScreenHeight, ScreenWidth, WindowName, Fullscreen);
			break;
		}

		printf("Game object initialised\n");
	}

	Game::~Game()
	{

	}

	int Game::Init()
	{
		m_WindowManager->InitWindow();

		//m_WindowManager->UpdateWindow();
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
	}
}