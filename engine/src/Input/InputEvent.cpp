#include "Input/InputEvent.h"

namespace Crumb
{
	InputEvent::InputEvent()
	{
		printf("Womp");
	}
	InputEvent::InputEvent(std::function<void()> Callback, EInputAction GivenAction)
	{
		m_Action = GivenAction;

		m_Event = Event();
		m_Event.SetCallback(Callback);
	}

	InputEvent::~InputEvent()
	{

	}

	void InputEvent::CallEvent()
	{
		m_Event.Trigger();
	}
}