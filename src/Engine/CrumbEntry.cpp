#include <iostream>

#include "Core.h"


int main()
{
	/*
	* Entry point, open our engine and run it. 
	*/

	std::unique_ptr<Crumb::Core> Engine = std::make_unique<Crumb::Core>();
	return Engine->Run();

}
