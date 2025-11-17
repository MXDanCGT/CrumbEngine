#include "Core/Event.h"

namespace Crumb
{
	Event::Event()
	{
		m_Callback = nullptr;
	}

	Event::~Event()
	{
		m_Callback = nullptr; //Is this ok or memory leak?
	}

	void Event::Trigger()
	{
		if (GetCallback())
		{
			m_Callback();
		}
	}
}