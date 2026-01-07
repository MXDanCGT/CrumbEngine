#pragma once
#include "InputCodes.h"
#include "Core/Event.h"


namespace Crumb
{

	/*
	* Input actions are events we bind key presses to in an abstracted way so as to remain platform independent
	*/
	class InputEvent
	{
	public:
		InputEvent();
		InputEvent(std::function<void()> Callback);
		~InputEvent();


		/*Triggered when we need that callback*/
		void CallEvent();

		/*Action needed on our bound key to trigger this event*/
		InputActionCode m_Action;

	private:

		/*What do we actually want to do when this input is met?*/
		Event m_Event;

	};
}