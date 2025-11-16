#pragma once
#include "pch.h"

#include "Game/Game.h"

/*
* Example extension of the Crumb game object
*/
	
class MorgCraft : public Crumb::Game
{
public:

	MorgCraft(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen = false);
	~MorgCraft();

	virtual void Tick(float DeltaTime) override;
};