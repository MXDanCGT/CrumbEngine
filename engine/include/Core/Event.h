#pragma once
#include "pch.h"

/**
*Events contain callbacks to trigger at specific times
* E.G.:the application programmer could bind an event to a certain keypress
*/
namespace Crumb
{
	class Event
	{
	public:

		Event();
		~Event();

		void Trigger();

		/*GETS N SETS*/
		inline std::function<void()> GetCallback() { return m_Callback; }
		inline void SetCallback(std::function<void()> Callback) { m_Callback = Callback; }

	private:

		/*Function pointer called on this events' callback*/
		std::function<void()> m_Callback;
	
	};

}