#pragma once
#include "InputCodes.h"
#include "Core/Event.h"


namespace Crumb
{

	/*
	* Input actions are events we bind key presses to in an abstracted way so as to remain platform independent
	* 
	* Not a componet (?)
	*/
	//class InputEvent
	//{
	//public:
	//	InputEvent();
	//	InputEvent(std::function<void()> Callback);
	//	InputEvent(std::function<void(float)> Callback);
	//	~InputEvent();


	//	/*Triggered when we need that callback*/
	//	void CallEvent();

	//	/*Action needed on our bound key to trigger this event*/
	//	InputActionCode m_Action;

	//	void SetAxisValue(float G);

	//private:

	//	/*What do we actually want to do when this input is met?*/
	//	Event m_Event;

	//};

	//Feature needed to add system
	struct FInputFeature {}; //Not sure why this is the case, just as it is in ECS_HPPs example stuff

	struct FInputEvent
	{
		InputKeyCode Key;
		InputActionCode Action;
	};

	/*
	* The actual "events" occuring, what is passed in to our input updates
	*/
	struct FInputEvents
	{
		std::vector<FInputEvent> InputEvents;
	};

	/*
	* Input bindings also have a event with callback functionality...
	*/
	struct FInputBinding : public FInputEvent
	{

		FInputBinding() {};

		FInputBinding(std::function<void()> Callback, InputKeyCode InputKey, InputActionCode InputAction)
		{
			Key = InputKey;
			Action = InputAction;

			Event.SetCallback(Callback);
		}


		Event Event;
	};

	/*
	* Component entities have that lists a number of Input Events that this entity wants to call on set bindings
	*/
	struct FCInputManager
	{
		FCInputManager()
		{
			InputBindings = {};
		}

		FCInputManager(FCInputManager& g)
		{
			InputBindings = g.InputBindings;
		}

		FCInputManager(const FCInputManager& g)
		{
			InputBindings = g.InputBindings;
		}

		template <typename T>
		void BindInputEvent(T* Inst, void (T::* Callback)(), InputKeyCode KeyPress, InputActionCode KeyAction)
		{
			auto CallbackLambda = [Inst, Callback]()
			{
				(Inst->*Callback)();
			};

			//Create an input event with the given func, key press and action
			FInputBinding Binding(CallbackLambda, KeyPress, KeyAction);


			InputBindings.push_back(Binding);
		}

		std::vector<FInputBinding> InputBindings;
	};

}