#include "Core/Event.h"

namespace Crumb
{
	Event::Event()
	{
		m_AxisValue = 0;
		m_Callback = nullptr;
		m_Callback_Axis = nullptr;
	}

	Event::~Event()
	{
		m_Callback = nullptr; //Is this ok or memory leak?
		m_Callback_Axis = nullptr;
	}

	void Event::Trigger()
	{
		switch (FuncNum)
		{

			case 0:
					if (GetCallback())
					{
						m_Callback();
					}
					break;

			case 1:
				if (GetCallbackAxis())
				{
					m_Callback_Axis(m_AxisValue);
				}
		}

	}
}