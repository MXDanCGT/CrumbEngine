#pragma once

#include "Input/InputEvent.h"
#include "ecs.hpp/ecs.hpp"


namespace Crumb
{
	//ECS impl of input, is given a list of incoming inputs and iterates through entities that have something to do in that context...
	

	class InputActionSystem : public ecs_hpp::system<FKeyStateTracker>
	{
	public:

		void process(ecs_hpp::registry& world, const FKeyStateTracker& evt) override;
	};

	/*
	* For AXIS, TODO:
	* Im not really sure if this is the best way to do things, seperate out the Action bindings and Axis bindings into 2 different systems
	*/
	class InputAxisSystem : public ecs_hpp::system<FAxisStateTracker>
	{
	public:

		void process(ecs_hpp::registry& world, const FAxisStateTracker& evt) override;
	};
}