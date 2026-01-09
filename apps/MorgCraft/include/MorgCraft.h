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
	void SayFoo() { printf("Foo"); }


	/*TODO this is a mess, allow us to have an axis value passed in to our bound functions*/
	void MoveCameraForward();
	void MoveCameraBack();
	void MoveCameraLeft();
	void MoveCameraRight();

	void MoveCameraUp();
	void MoveCameraDown();

	float Delta;
};