#include "Core.h"
#include "WindowManager.h"
#include <iostream>

namespace Crumb
{
	Core::Core()
	{

	}

	Core::~Core()
	{

	}

	int Core::Run()
	{
		/*
		* Our "game" is a library being imported.
		* 
		* All "app" layer starts with a blank window to write to
		*/
		std::unique_ptr<MWindowManager> WindowManager = std::make_unique<MWindowManager>(800, 600, "Crumb Engine");
		return WindowManager->InitWindow();
	}

}