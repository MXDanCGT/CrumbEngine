#include "Input/InputSystem.h"
#include "Core/CoreComponents.h"
namespace Crumb
{
	void Crumb::InputActionSystem::process(ecs_hpp::registry& world, const FKeyStateTracker& evt)
	{
		world.for_each_component<FCInputManager>(
			[&evt](ecs_hpp::entity, FCInputManager& bindings)
			{
				for (auto& i : bindings.InputBindings)
				{
					auto it = evt.KeyStates.find(i.Key);
					if (it == evt.KeyStates.end())
						continue; //Not bound

					const FKeyState State = it->second;

					if (State.CurrentAction != i.Action)
					{
						//If the action we want is pressed and held and we are pressing or holding we can trigger
						if (!(i.Action == CRUMB_PRESSED_AND_HELD && State.CurrentAction == CRUMB_PRESSED || i.Action == CRUMB_PRESSED_AND_HELD && State.CurrentAction == CRUMB_HELD))
							//If required = pressed and held and we are pressing or holding
							continue; //TODO this is a bit gory
					}
					i.Event.Trigger(); //Do the callback!

				}

			}, !ecs_hpp::exists<FCDisabled>{}
				);
	}


	void Crumb::InputAxisSystem::process(ecs_hpp::registry& world, const FAxisStateTracker& evt)
	{
		world.for_each_component<FCInputManager>(
			[&evt](ecs_hpp::entity, FCInputManager& bindings)
			{
				for (auto& i : bindings.AxisBindings)
				{
					auto it = evt.AxisStates.find(i.Key);
					if (it == evt.AxisStates.end())
						continue;

					const float Value = it->second;
					i.Event.Trigger(Value);

				}

			}



		);


	}
}