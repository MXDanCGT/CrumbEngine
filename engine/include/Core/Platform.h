#pragma once

enum EPS_Window : uint8_t
{
	EPS_W_GLFW = 0
};

/*Platform settings struct allowing for the application user to change the implementations called...*/
struct FPlatformSettings
{
	FPlatformSettings() {};
	/*Desired window implementation*/
	EPS_Window WindowPlatform = EPS_Window::EPS_W_GLFW;
};
