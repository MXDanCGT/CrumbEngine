#pragma once

#include "Core/Event.h"

/*
* Input actions are events we bind key presses to in an abstracted way so as to remain platform independent
*/



namespace Crumb
{
	enum EInputCode; //Forward decl
	enum EInputAction;

	class InputEvent
	{
	public:
		InputEvent();
		InputEvent(std::function<void()> Callback, EInputAction GivenAction);
		~InputEvent();


		/*Triggered when we need that callback*/
		void CallEvent();

		/*Action needed on our bound key to trigger this event*/
		EInputAction m_Action;

	private:

		/*What do we actually want to do when this input is met?*/
		Event m_Event;

	};
}