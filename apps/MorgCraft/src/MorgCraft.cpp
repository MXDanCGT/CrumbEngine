#include "MorgCraft.h"


MorgCraft::MorgCraft(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen) : Game::Game(ScreenHeight, ScreenWidth, WindowName, Fullscreen)
{
	printf("MorgCraft is here!\n");
}

MorgCraft::~MorgCraft()
{
	printf("So long, MorgCraft");
}

void MorgCraft::Tick(float DeltaTime)
{
	Game::Tick(DeltaTime); //ALWAYS CALL SUPER
}