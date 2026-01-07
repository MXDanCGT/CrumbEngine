#include "MorgCraft.h"


MorgCraft::MorgCraft(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen) : Game::Game(ScreenHeight, ScreenWidth, WindowName, Fullscreen)
{
	printf("MorgCraft is here!\n");

	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::SayFoo, this, Crumb::CRUMB_W, Crumb::CRUMB_PRESSED);
}

MorgCraft::~MorgCraft()
{

}

void MorgCraft::Tick(float DeltaTime)
{
	Game::Tick(DeltaTime); //ALWAYS CALL SUPER

	//Your game loop functionality goes here
}