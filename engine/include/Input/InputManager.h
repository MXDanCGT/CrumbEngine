#pragma once

#include "InputEvent.h"
#include "InputCodes.h"

struct FPlatformSettings;

namespace Crumb
{


	/*Input manager class, allowing us to abstract input management from the library used*/
    class MInputManager
    {
    public:

        MInputManager();
        ~MInputManager();


        /*Move through our input event queue, invoking the callbacks in turn*/
        void Update();

        void QueueInputEvent(InputEvent Event) { InputEventQueue.push(Event); }

        void LogInputEvent(int LibKey, int LibAction, int LibMods);


        template <typename T>
        void BindInputEvent(void (T::* Callback)(), T* Perfromer, InputKeyCode KeyPress, InputActionCode KeyAction) //Create an input event on a passed in function - a function to call when  
        {
            /*lambda functions CAN be converted to std::functions...*/
            auto CallbackLambda = [Perfromer, Callback]()
            {
              (Perfromer->*Callback)();
            };

            InputEventMapping[KeyPress] = InputEvent(CallbackLambda);
        }
        /*Bind input event overload for our scalar events*/
        template <typename T>
        void BindInputEvent(void (T::* Callback)(float), T* Perfromer, InputKeyCode KeyPress, InputActionCode KeyAction) //Create an input event on a passed in function - a function to call when  
        {
            /*lambda functions CAN be converted to std::functions...*/
            auto CallbackLambda = [Perfromer, Callback](float value)
                {
                    (Perfromer->*Callback)(value);
                };

            InputEventMapping[KeyPress] = InputEvent(CallbackLambda);
        }

        /*None GLFW version - glfw needs us to keep track of the mouse position ourselves to circumvent c style func pointer mess*/
        void LogMouseMove(double XPos, double YPos, double* OldPos);

        /*Similar to Bind Input Event but we have an amount parameter*/

        /*Returns the equivelant key in Crumb Numbers correspodnign to the library key code*/
        virtual InputKeyCode GetCrumbKey(int LibKey);

        virtual InputActionCode GetCrumbAction(int LibAction);


	protected:

		/*Only overloaded function, might get a bit hefty*/
        inline virtual void InitLibKey() {};

		/*Map equating our Crumb EInputCodes to the ones represented in whichever library TODO IS INT GOOD FOR ALL LIBS?*/
		std::unordered_map<int, InputKeyCode> LibKeyMap;

        /*Map equating our Crumb EInputTypes to the ones represented in whichever library*/
        std::map<int, InputActionCode> LibActionMap;

        /*Map an input code to doing a specific event*/
        std::map<InputKeyCode, InputEvent> InputEventMapping;
        /*Said input event queue*/
        std::queue<InputEvent> InputEventQueue;

	};


	class MInputManager_GLFW : public MInputManager
	{
    public:
        MInputManager_GLFW();



        void LogMouseMove(double XPos, double YPos);

	private:

        double* m_MousePos;

        /*As said, the Crumb key codes are identical to the GLFW key codes; if we wanted to implement a new library with different codes, we wouldnt override this, and instead setup a new map*/
        virtual InputKeyCode GetCrumbKey(int GLFWKey) override;

        /*As said, the Crumb key codes are identical to the GLFW key codes; if we wanted to implement a new library with different codes, we wouldnt override this, and instead setup a new map*/
        virtual InputActionCode GetCrumbAction(int GLFWAction) override;
	};
}