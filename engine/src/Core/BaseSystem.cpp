#include "Core/BaseSystem.h"


#include "Core/CoreComponents.h"

namespace Crumb
{

	BaseSystem_GameplayEvent::BaseSystem_GameplayEvent()
	{
		printf(" system initialised");
	}

	BaseSystem_GameplayEvent::~BaseSystem_GameplayEvent()
	{
		printf(" system offline");
	}

	void BaseSystem_GameplayEvent::process(ecs_hpp::registry& world, const FGameplayEvent& evt)
	{
		printf(" system processing...");
	}
	//Filters etc. can be added at the system specific level...

}