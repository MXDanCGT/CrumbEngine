#pragma once

#include "ecs.hpp/ecs.hpp"


namespace Crumb
{
	/**
	* Event in our ECS system, has a deltatime param
	*
	* Gameplay systems we want to run on tick should be built off this...
	*/
	struct FGameplayEvent
	{
		float DeltaTime{};
	};


	/*
	* Our base ECS system functionality...
	*/
	class BaseSystem_GameplayEvent : public ecs_hpp::system<FGameplayEvent> 
	{
	public: 

		BaseSystem_GameplayEvent();
		~BaseSystem_GameplayEvent();


		void process(ecs_hpp::registry& world, const FGameplayEvent& evt) override;

	};

}