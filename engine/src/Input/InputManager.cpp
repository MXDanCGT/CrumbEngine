#include "Input/InputManager.h"

#include "Core/Platform.h"

namespace Crumb
{
	MInputManager::MInputManager()
	{
		InitLibKey();
	}

	MInputManager_GLFW::MInputManager_GLFW() : MInputManager::MInputManager()
	{
		m_MousePos = new double[2] {0.f, 0.f};
	}

	MInputManager::~MInputManager()
	{

	}

	//template <typename T>
	//void MInputManager::BindInputEvent(void (T::* Callback)(), InputKeyCode KeyPress, InputActionCode KeyAction)
	//{
	//	//Create an input event with the given func, key press and action

	//	//TODO MULTIPLE BINDINGS TO EACH KEY??
	//	//Hash the key combination? 

	//	//InputEventMapping.insert({KeyPress, InputEvent(Callback, KeyAction) });
	//}

	void MInputManager::LogInputEvent(int LibKey, int LibAction, int LibMods)
	{
		//Im a little confused admiteddly, this isnt a static func so calling this with IM shouldnt be necessary

		////Step 1 - convert the input key into Crumb Keys
		InputKeyCode CrumbKey =  GetCrumbKey(LibKey);//TODO REINTRODUCE USE OF GETCRUMBKEY SO WE CAN KEEP LIBRARY / PLATFORM AGNOSTICISM
		InputActionCode CrumbAction = GetCrumbAction(LibAction);


		if (InputEventMapping.find(CrumbKey) != InputEventMapping.end()) //If this key is mapped
		{
			//TODO Input Events with context mapping, i.e.: pressed, released...
			InputEvent ToPush = InputEventMapping[CrumbKey];
			if (ToPush.m_Action = GetCrumbAction(LibAction))
			{
				InputEventQueue.push(ToPush); //Do this input event...
			}
			return;
		}

		if(CrumbAction == CRUMB_PRESSED)
			printf("Input key %d pressed but no input bound\n", CrumbKey);
	}

	void MInputManager::LogMouseMove(double XPos, double YPos, double* OldPos)
	{
		if (OldPos[0] == XPos && OldPos[1] == YPos)
			return;
	
	
		double Offset[2] = { OldPos[0] - XPos, OldPos[1] - YPos };

		//500 for X 501 for Y (in GL input stuffs)

		//InputKeyCode CrumbMouseX = GetCrumbKey(500);
		//InputKeyCode CrumbMouseY = GetCrumbKey(501);
		//InputEvent ToPush = InputEventMapping[CrumbMouseX];

		//Input events are TEMPORARY!

		//For now lets just say...
		InputKeyCode CrumbX = GetCrumbKey(500);
		InputKeyCode CrumbY = GetCrumbKey(501);

		if (InputEventMapping.find(CrumbX) != InputEventMapping.end())
		{
			InputEvent ToPush = InputEventMapping[CrumbX];
			ToPush.SetAxisValue(Offset[0]);
			InputEventQueue.push(ToPush);
		}

		if (InputEventMapping.find(CrumbY) != InputEventMapping.end())
		{
			InputEvent ToPush = InputEventMapping[CrumbY];
			ToPush.SetAxisValue(Offset[1]);
			InputEventQueue.push(ToPush);
		}
	}



	void MInputManager_GLFW::LogMouseMove(double XPos, double YPos)
	{
		MInputManager::LogMouseMove(XPos, YPos, m_MousePos);
		m_MousePos = new double[2] { XPos, YPos}; //Does this memory leak?
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

	InputKeyCode MInputManager::GetCrumbKey(int LibKey)
	{
		return LibKeyMap[LibKey];
	}

	InputActionCode MInputManager::GetCrumbAction(int LibKey)
	{
		return LibActionMap[LibKey];
	}


	InputKeyCode MInputManager_GLFW::GetCrumbKey(int LibKey)
	{
		return LibKey;
	}

	InputActionCode MInputManager_GLFW::GetCrumbAction(int LibAction)
	{
		return LibAction;
	}
}