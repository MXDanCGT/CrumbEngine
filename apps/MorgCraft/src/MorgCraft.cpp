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
	PlayerInp.BindInputEvent<MorgCraft>(this, &MorgCraft::SayFoo, CRUMB_W, CRUMB_PRESSED);

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
	m_MainCamera->MoveCamera_UpDown(100.f * Delta);
}

void MorgCraft::MoveCameraDown()
{
	m_MainCamera->MoveCamera_UpDown(-100.f * Delta);
}

void MorgCraft::MoveCameraForward()
{
	m_MainCamera->MoveCamera_ForwardBackward(100.f * Delta);
}

void MorgCraft::MoveCameraBack()
{
	m_MainCamera->MoveCamera_ForwardBackward(-100.f * Delta);
}

void MorgCraft::MoveCameraLeft()
{
	m_MainCamera->MoveCamera_LeftRight(-100.f * Delta);
}

void MorgCraft::MoveCameraRight()
{
	m_MainCamera->MoveCamera_LeftRight(100.f * Delta);
}