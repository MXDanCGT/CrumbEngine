#pragma once

#include "Input/InputEvent.h"
#include "ecs.hpp/ecs.hpp"


namespace Crumb
{
	//ECS impl of input, is given a list of incoming inputs and iterates through entities that have something to do in that context...
	

	class InputSystem : public ecs_hpp::system<FInputEvents>
	{
	public:

		void process(ecs_hpp::registry& world, const FInputEvents& evt) override;
	};
}