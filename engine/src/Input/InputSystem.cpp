#include "Input/InputSystem.h"
#include "Core/CoreComponents.h"

void Crumb::InputSystem::process(ecs_hpp::registry& world, const FInputEvents& evt)
{
	world.for_each_component<FCInputManager>(
		[&evt](ecs_hpp::entity, FCInputManager& bindings) 
		{
			for (auto&i : bindings.InputBindings)
			{
				//See if this action exists in our input event
				for (auto& j : evt.InputEvents)
				{
					if (j.Key != i.Key)
						continue;

					if (j.Action != i.Action)
						continue;

					i.Event.Trigger(); //Do the callback!
				}
			}

		}, !ecs_hpp::exists<FCDisabled>{}
	);
}
