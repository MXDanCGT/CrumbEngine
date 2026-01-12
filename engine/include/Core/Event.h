#pragma once
#include "pch.h"

/**
*Events contain callbacks to trigger at specific times
* E.G.:the application programmer could bind an event to a certain keypress
*/
namespace Crumb
{
	/*
	* Feels hacky, but the way we've set up our input system it only really works to have one vent class and have like a pointer to the one we wanna use
	*/
	class Event
	{
	public:

		Event();
		~Event();

		virtual void Trigger() const;

		/*GETS N SETS*/

		inline unsigned char GetFuncNum() { return FuncNum; }
		inline void SetFuncNum(unsigned char G) { FuncNum = G; }

		inline std::function<void()> GetCallback() const { return m_Callback; }
		inline void SetCallback(std::function<void()> Callback) { m_Callback = Callback; }

		inline std::function<void(float)> GetCallbackAxis() const { return m_Callback_Axis; }
		inline void SetCallbackAxis(std::function<void(float)> Callback) { m_Callback_Axis = Callback; }

		inline float GetAxisValue() { return m_AxisValue; }
		inline void SetAxisValue(float G) { m_AxisValue = G; }

	private:

		/*Are we using our void or void(float) callback? 0 | 1*/
		unsigned char FuncNum;

		/*If we are using an axis callback, the value we will pass into said callback*/
		float m_AxisValue;

		/*Function pointer called on this events' callback*/
		std::function<void()> m_Callback;

		/*Function pointer for calling this events' callback and recievinng a scalar input*/
		std::function<void(float)> m_Callback_Axis;
	
	};


}