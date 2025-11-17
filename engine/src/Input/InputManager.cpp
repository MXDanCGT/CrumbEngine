#include "Input/InputManager.h"

#include "Core/Platform.h"

namespace Crumb
{
	MInputManager::MInputManager()
	{
		InitLibKey();
	}

	MInputManager::~MInputManager()
	{

	}

	void MInputManager::BindInputEvent(std::function<void()> Callback, EInputCode KeyPress, EInputAction KeyAction)
	{
		//Create an input event with the given func, key press and action

		//TODO MULTIPLE BINDINGS TO EACH KEY??

		InputEventMapping.insert({ KeyPress, InputEvent(Callback, KeyAction) });
	}

	void MInputManager::LogInputEvent(int LibKey, int LibAction)
	{
		//Step 1 - convert the input key into Crumb Keys
		EInputCode CrumbKey = static_cast<EInputCode>(GetCrumbKey(LibKey)); //Explicit cast hmmm
		//TODO WHAT IF A NUMBER NOT IN THE LIST IS PASSED IN??

		if (InputEventMapping.find(CrumbKey) != InputEventMapping.end()) //If this key is mapped
		{
			//TODO Input Events with context mapping, i.e.: pressed, released...
			InputEvent ToPush = InputEventMapping[CrumbKey];
			if (ToPush.m_Action = static_cast<EInputAction>(GetCrumbAction(LibAction)))
			{
				InputEventQueue.push(ToPush);
			}
		}
	}

	void MInputManager::Update()
	{
		for (int i = 0; i < InputEventQueue.size(); ++i)
		{
			InputEvent Event = InputEventQueue.front();
			InputEventQueue.pop();
			Event.CallEvent();
		}
	}
}