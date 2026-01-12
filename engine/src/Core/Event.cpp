#include "Core/Event.h"

namespace Crumb
{
	Event_Action::Event_Action()
	{
		m_AxisValue = 0;
		m_Callback = nullptr;
	}

	Event_Action::~Event_Action()
	{
		m_Callback = nullptr; //Is this ok or memory leak?
	}

	void Event_Action::Trigger() const
	{
		if (GetCallback())
		{
			m_Callback();
		}

	}


	Event_Axis::Event_Axis()
	{
		m_AxisValue = 0;
		m_Callback = nullptr;
	}

	Event_Axis::~Event_Axis()
	{
		m_Callback = nullptr; //Is this ok or memory leak?
	}

	void Event_Axis::Trigger(float value) const
	{
		if (GetCallback())
		{
			m_Callback(value);
		}

	}
}