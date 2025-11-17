#pragma once

#include "InputEvent.h"
struct FPlatformSettings;

namespace Crumb
{

	/*Crumb key defs act as a library agnostic abstraction of input codes*/
	enum EInputCode : int
	{
		/*These are the same as the GLFW numbers
		But can be used for other libraries if so wished and a new map provided*/

 	    EIC_SPACE = 32,
 	    EIC_APOSTROPHE = 39, /* ' */
 	    EIC_COMMA = 44 ,/* , */
 	    EIC_MINUS = 45, /* - */
 	    EIC_FULLSTOP = 46, /* . */
 	    EIC_SLASH = 47, /* / */
 	    EIC_0 = 48, /* 0 */
 	    EIC_1 = 49, /* 1 */
 	    EIC_2 = 50, /* 2 */
 	    EIC_3 = 51, /* 3 */
 	    EIC_4 = 52, /* 4 */
 	    EIC_5 = 53, /* 5 */
 	    EIC_6 = 54, /* 6 */
 	    EIC_7 = 55, /* 7 */
 	    EIC_8 = 56, /* 8 */
 	    EIC_9 = 57, /* 9 */
 	    EIC_SEMICOLON = 59,  /* ; */
 	    EIC_EQUALs = 61, /* = */
 	    EIC_A = 65, /* A */
 	    EIC_B = 66, /* B */
 	    EIC_C = 67, /* C */
 	    EIC_D = 68, /* D */
 	    EIC_E = 69, /* E */
 	    EIC_F = 70, /* F */
 	    EIC_G = 71, /* G */
 	    EIC_H = 72, /* H */
 	    EIC_I = 73, /* I */
 	    EIC_J = 74, /* J */
 	    EIC_K = 75, /* K */
 	    EIC_L = 76, /* L */
 	    EIC_M = 77, /* M */
 	    EIC_N = 78, /* N */
 	    EIC_O = 79, /* O */
 	    EIC_P = 80, /* P */
 	    EIC_Q = 81, /* Q */
 	    EIC_R = 82, /* R */
 	    EIC_S = 83, /* S */
 	    EIC_T = 84, /* T */
 	    EIC_U = 85, /* U */
 	    EIC_V = 86, /* V */
 	    EIC_W = 87, /* W */
 	    EIC_X = 88, /* X */
 	    EIC_Y = 89, /* Y */
 	    EIC_Z = 90, /* Z */
 	    EIC_LEFT_BRACKET = 91, /* [ */
 	    EIC_BACKSLASH = 92, /* \ */
 	    EIC_RIGHT_BRACKET = 93, /* ] */
 	    EIC_GRAVE_ACCENT = 96,  /* ` */
 	    EIC_WORLD_1 = 161, 
 	    EIC_WORLD_2 = 162,
 	    EIC_ESCAPE = 256,
 	    EIC_ENTER = 257,
 	    EIC_TAB = 258,
 	    EIC_BACKSPACE = 259,
 	    EIC_INSERT = 260,
 	    EIC_DELETE = 261,
 	    EIC_RIGHT = 262,
 	    EIC_LEFT = 263,
 	    EIC_DOWN = 264,
 	    EIC_UP = 265,
 	    EIC_PAGE_UP = 266,
 	    EIC_PAGE_DOWN = 267,
 	    EIC_HOME = 268,
 	    EIC_END = 269,
 	    EIC_CAPS_LOCK = 280,
 	    EIC_SCROLL_LOCK = 281,
 	    EIC_NUM_LOCK = 282,
 	    EIC_PRINT_SCREEN = 283,
 	    EIC_PAUSE = 284,
 	    EIC_F1 = 290,
 	    EIC_F2 = 291,
 	    EIC_F3 = 292,
 	    EIC_F4 = 293,
 	    EIC_F5 = 294,
 	    EIC_F6 = 295,
 	    EIC_F7 = 296,
 	    EIC_F8 = 297,
 	    EIC_F9 = 298,
 	    EIC_F10 = 299,
 	    EIC_F11 = 300,
 	    EIC_F12 = 301,
 	    EIC_F13 = 302,
 	    EIC_F14 = 303,
 	    EIC_F15 = 304,
 	    EIC_F16 = 305,
 	    EIC_F17 = 306,
 	    EIC_F18 = 307,
 	    EIC_F19 = 308,
 	    EIC_F20 = 309,
 	    EIC_F21 = 310,
 	    EIC_F22 = 311,
 	    EIC_F23 = 312,
 	    EIC_F24 = 313,
 	    EIC_F25 = 314,
 	    EIC_KP_0 = 320,
 	    EIC_KP_1 = 321,
 	    EIC_KP_2 = 322,
 	    EIC_KP_3 = 323,
 	    EIC_KP_4 = 324,
 	    EIC_KP_5 = 325,
 	    EIC_KP_6 = 326,
 	    EIC_KP_7 = 327,
 	    EIC_KP_8 = 328,
	    EIC_KP_9 = 329,
 	    EIC_KP_DECIMAL = 330,
 	    EIC_KP_DIVIDE = 331,
 	    EIC_KP_MULTIPLY = 332,
 	    EIC_KP_SUBTRACT = 333,
 	    EIC_KP_ADD = 334,
 	    EIC_KP_ENTER = 335,
 	    EIC_KP_EQUAL = 336,
 	    EIC_LEFT_SHIFT = 340,
 	    EIC_LEFT_CONTROL = 341,
 	    EIC_LEFT_ALT = 342,
 	    EIC_LEFT_SUPER = 343,
 	    EIC_RIGHT_SHIFT = 344,
 	    EIC_RIGHT_CONTROL = 345,
 	    EIC_RIGHT_ALT = 346,
 	    EIC_RIGHT_SUPER = 347,
 	    EIC_MENU = 348

	};
	
    /*Crumb key defs as before for the type of input, i.e.: pressed / released*/
    enum EInputAction : int
    {
        /*Again, same as GLFW values; other lib implementations would have to define a map to swap between*/
        EIA_RELEASED = 0,
        EIA_PRESSED = 1
    };

	/*Input manager class, allowing us to abstract input management from the library used*/
	class MInputManager
	{
	public:

		MInputManager();
		~MInputManager();


        /*Move through our input event queue, invoking the callbacks in turn*/
        void Update();


        void QueueInputEvent(InputEvent Event) { InputEventQueue.push(Event); }

        void LogInputEvent(int LibKey, int LibAction);

        void BindInputEvent(std::function<void()> Callback, EInputCode KeyPress, EInputAction KeyAction); //Create an input event on a passed in function - a function to call when  

	protected:

		/*Only overloaded function, might get a bit hefty*/
        inline virtual void InitLibKey() {};

		/*Map equating our Crumb EInputCodes to the ones represented in whichever library TODO IS INT GOOD FOR ALL LIBS?*/
		std::map<int, EInputCode> LibKeyMap;

        /*Map equating our Crumb EInputTypes to the ones represented in whichever library*/
        std::map<int, EInputAction> LibActionMap;

        /*Map an input code to doing a specific event*/
        std::map<EInputCode, InputEvent> InputEventMapping;

        

        /*Said input event queue*/
        std::queue<InputEvent> InputEventQueue;

        /*Returns the equivelant key in Crumb Numbers correspodnign to the library key code*/
        inline virtual int GetCrumbKey(int LibKey) { return LibKeyMap[LibKey]; }

        inline virtual int GetCrumbAction(int LibAction) { return LibActionMap[LibAction]; }

	};


	class MInputManager_GLFW : public MInputManager
	{
	private:

        /*As said, the Crumb key codes are identical to the GLFW key codes; if we wanted to implement a new library with different codes, we wouldnt override this, and instead setup a new map*/
        inline virtual int GetCrumbKey(int GLFWKey) override { return GLFWKey; }

        /*As said, the Crumb key codes are identical to the GLFW key codes; if we wanted to implement a new library with different codes, we wouldnt override this, and instead setup a new map*/
        inline virtual int GetCrumbAction(int GLFWAction) override { return GLFWAction; }
	};
}