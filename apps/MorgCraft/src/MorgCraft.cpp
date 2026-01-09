#include "MorgCraft.h"


using namespace Crumb;

MorgCraft::MorgCraft(int ScreenHeight, int ScreenWidth, std::string WindowName, bool Fullscreen) : Game::Game(ScreenHeight, ScreenWidth, WindowName, Fullscreen)
{
	printf("MorgCraft is here!\n");

	//TOOD a begin play function?
	Delta = 0.f;

	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::MoveCameraForward, this, CRUMB_W, CRUMB_PRESSED);
	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::MoveCameraBack, this, CRUMB_S, CRUMB_PRESSED);
	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::MoveCameraLeft, this, CRUMB_A, CRUMB_PRESSED);
	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::MoveCameraRight, this, CRUMB_D, CRUMB_PRESSED);

	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::MoveCameraUp, this, CRUMB_E, CRUMB_PRESSED);
	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::MoveCameraDown, this, CRUMB_Q, CRUMB_PRESSED);

	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::LookCameraLeftRight, this, CRUMB_MOUSE_X_AXIS, CRUMB_PRESSED);
	m_InputManager->BindInputEvent<MorgCraft>(&MorgCraft::LookCameraUpDown, this, CRUMB_MOUSE_Y_AXIS, CRUMB_PRESSED);
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
	printf("\n X Offset of - %f \n", LR);
}

void MorgCraft::LookCameraUpDown(float UD)
{
	printf("\n Y Offset of - %f \n", UD);
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