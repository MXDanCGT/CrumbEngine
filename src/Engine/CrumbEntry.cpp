#include <iostream>

#include "Core.h"


int main()
{
	/*
	*/

	std::unique_ptr<Crumb::Core> Engine = std::make_unique<Crumb::Core>();
	printf("Crumb Engine Launching...\n");
	return Engine->Run();

}
