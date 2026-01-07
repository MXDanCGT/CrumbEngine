#include <memory>

#include "Core/Core.h"
#include "MorgCraft.h"

int main()
{
	/*
	* Your programs entry point goes here....
	*/

	/*Define the game object*/
	std::unique_ptr<MorgCraft> morgCraft = std::make_unique<MorgCraft>(800, 600, "MorgCraft", false);
	/*Set some settings*/


	/*Setup the engine core with our game object*/
	std::unique_ptr<Crumb::Core> MorgCraft_Core = std::make_unique<Crumb::Core>(std::move(morgCraft)); //Initialise a core with your game object
	
	/*Init*/
	MorgCraft_Core->Init();
	/*Run!*/
	return MorgCraft_Core->Run();

}