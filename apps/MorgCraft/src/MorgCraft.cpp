#include "MorgCraft.h"

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>

#include "MCWorld.h"

using namespace Crumb;

MorgCraft::MorgCraft(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen) : Game::Game(ScreenHeight, ScreenWidth, WindowName, Fullscreen)
{
	printf("MorgCraft is here!\n");

	//TOOD a begin play function?
	Delta = 0.f;


	m_World = std::make_unique<MCWorld>();

	//The pitfall of doing it this way is that inputs have to belong to an entity - in this case typically the player, or maybe a controller, but all the same.
	FCInputManager PlayerInp;
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::MoveCameraForward, CRUMB_W, CRUMB_PRESSED_AND_HELD);
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::MoveCameraBack, CRUMB_S, CRUMB_PRESSED_AND_HELD);
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::MoveCameraLeft, CRUMB_A, CRUMB_PRESSED_AND_HELD);
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::MoveCameraRight, CRUMB_D, CRUMB_PRESSED_AND_HELD);
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::MoveCameraUp, CRUMB_E, CRUMB_PRESSED_AND_HELD);
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::MoveCameraDown, CRUMB_Q, CRUMB_PRESSED_AND_HELD);

	//Make a "player" entity here
	ecs_hpp::entity PlayerEnt = m_GameRegistry.create_entity();
	ecs_hpp::entity_filler(PlayerEnt)
		.component<FCInputManager>(PlayerInp);

	//Adding input bindings now...
	
}

MorgCraft::~MorgCraft()
{

}

void MorgCraft::Tick(float DeltaTime)
{
	Game::Tick(DeltaTime); //ALWAYS CALL SUPER

	//Your game loop functionality goes here
	Delta = DeltaTime;
}


void MorgCraft::LookCameraLeftRight(float LR)
{
	//Can we get away with just changing camera direction?

	m_MainCamera->RotateCamera({0.f, 0.f, LR * Delta * 100.f});
	
}

void MorgCraft::LookCameraUpDown(float UD)
{
	//Clamped to avoid Gimbal lock + - so its the way youd expect
	m_MainCamera->RotateCamera({ 0.f, std::clamp(-UD * Delta * 100.f, -89.f, 89.f), 0.f });
}



/*
* TEMP SERVICABLE DEBUG MOVEMENTS...
*/
void MorgCraft::MoveCameraUp()
{
	m_MainCamera->MoveCamera_UpDown(2.f * Delta);
}

void MorgCraft::MoveCameraDown()
{
	m_MainCamera->MoveCamera_UpDown(-2.f * Delta);
}

void MorgCraft::MoveCameraForward()
{
	m_MainCamera->MoveCamera_ForwardBackward(2.f * Delta);
}

void MorgCraft::MoveCameraBack()
{
	m_MainCamera->MoveCamera_ForwardBackward(-2.f * Delta);
}

void MorgCraft::MoveCameraLeft()
{
	m_MainCamera->MoveCamera_LeftRight(-2.f * Delta);
}

void MorgCraft::MoveCameraRight()
{
	m_MainCamera->MoveCamera_LeftRight(2.f * Delta);
}