#pragma once
#include "pch.h"

#include "Core/Game.h"

/*
* Example extension of the Crumb game object
*/
	
class MorgCraft : public Crumb::Game
{
public:

	MorgCraft(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen = false);
	~MorgCraft();

	virtual void Tick(float DeltaTime) override;

	/*Debug tester function for input actions...*/
	inline void SayFoo() { printf("Foo"); }
};