#pragma once
#include "InputCodes.h"
#include "Core/Event.h"


namespace Crumb
{

	//Feature needed to add system
	struct FInputFeature {}; //Not sure why this is the case, just as it is in ECS_HPPs example stuff

	struct FKeyState
	{
		FKeyState()
		{
		}
		FKeyState(int NewAction)
		{
			CurrentAction = NewAction;
		}

		InputActionCode CurrentAction; //We keep this constant so we can see key state even if no new input events are coming through on it
	};

	/*
	* Keeps track of all our key states over the whole keyboard///
	*/
	struct FKeyStateTracker
	{
		std::unordered_map<InputKeyCode, FKeyState> KeyStates; //Persistent...
	};

	struct FAxisStateTracker
	{
		std::unordered_map<InputKeyCode, float> AxisStates; //Reset every frame
	};



	struct FInputEvent
	{
		InputKeyCode Key;
		InputActionCode Action;
	};

	/*
	* Input bindings also have a event with callback functionality...
	*/
	struct FInputActionBinding : public FInputEvent
	{

		FInputActionBinding() {};

		FInputActionBinding(std::function<void()> Callback, InputKeyCode InputKey, InputActionCode InputAction)
		{
			Key = InputKey;
			Action = InputAction;

			Event.SetCallback(Callback);
		}


		Event_Action Event;
	};

	struct FInputAxisBinding 
	{
		InputKeyCode Key; //IK mouse is  not techincally key but eh;

		FInputAxisBinding() {};

		FInputAxisBinding(std::function<void(float)> Callback, InputKeyCode InputKey)
		{
			Key = InputKey;

			Event.SetCallback(Callback);
		}


		Event_Axis Event; //Event that will use callback type 2.. TODO SEPERATE EVENT INTO AXIS AND ACTION BINDINGS?
	};


	/*
	* Component entities have that lists a number of Input Events that this entity wants to call on set bindings
	*/
	struct FCInputManager
	{
		FCInputManager()
		{
			InputBindings = {};
			AxisBindings = {};
		}

		FCInputManager(FCInputManager& g)
		{
			InputBindings = g.InputBindings;
			AxisBindings = g.AxisBindings;
		}

		FCInputManager(const FCInputManager& g)
		{
			InputBindings = g.InputBindings;
			AxisBindings = g.AxisBindings;
		}

		template <typename T>
		void BindInputActionEvent(T* Inst, void (T::* Callback)(), InputKeyCode KeyPress, InputActionCode KeyAction) //Does this "break ECS" having this in a component? its basically just a setter...
		{
			auto CallbackLambda = [Inst, Callback]()
			{
				(Inst->*Callback)();
			};

			//Create an input event with the given func, key press and action
			FInputActionBinding Binding(CallbackLambda, KeyPress, KeyAction);


			InputBindings.push_back(Binding);
		}

		//Im aware the grammar / order of whether its an input [blank] action or an input action [blank] changes in places, whoopsadasies

		template <typename T>
		void BindInputAxisEvent(T* Inst, void (T::* Callback)(float), InputKeyCode KeyPress)
		{
			auto CallbackLambda = [Inst, Callback](float value)
				{
					(Inst->*Callback)(value);
				};

			FInputAxisBinding Binding(CallbackLambda, KeyPress);

			AxisBindings.push_back(Binding);
		}

		std::vector<FInputActionBinding> InputBindings;

		std::vector<FInputAxisBinding> AxisBindings;
	};

}