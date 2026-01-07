#pragma once
#include <cstdint>

/*File for definition of input codes that the application programmer is exposed to*/
namespace Crumb
{
	//Are constexpr preferable over const

	/*Crumb codes representing keys - a middleman for the application programmer to use in place of defining specific library key definitions*/
	/*It is not a coincidence these are the same as the GLFW key codes*/
	typedef uint16_t InputKeyCode;

	/*Crumb key defs as before for the type of input, i.e.: pressed / released*/
	typedef unsigned char InputActionCode;

	//DEAR GOD HELP
	constexpr InputKeyCode CRUMB_SPACE = 32;
	constexpr InputKeyCode CRUMB_APOSTROPHE = 39; /* ' */
	constexpr InputKeyCode CRUMB_COMMA = 44; /* , */
	constexpr InputKeyCode CRUMB_MINUS = 45; /* - */
	constexpr InputKeyCode CRUMB_FULLSTOP = 46; /* . */
	constexpr InputKeyCode CRUMB_SLASH = 47; /* / */
	constexpr InputKeyCode CRUMB_0 = 48; /* 0 */
	constexpr InputKeyCode CRUMB_1 = 49; /* 1 */
	constexpr InputKeyCode CRUMB_2 = 50; /* 2 */
	constexpr InputKeyCode CRUMB_3 = 51; /* 3 */
	constexpr InputKeyCode CRUMB_4 = 52; /* 4 */
	constexpr InputKeyCode CRUMB_5 = 53; /* 5 */
	constexpr InputKeyCode CRUMB_6 = 54; /* 6 */
	constexpr InputKeyCode CRUMB_7 = 55; /* 7 */
	constexpr InputKeyCode CRUMB_8 = 56; /* 8 */
	constexpr InputKeyCode CRUMB_9 = 57; /* 9 */
	constexpr InputKeyCode CRUMB_SEMICOLON = 59;  /* ; */
	constexpr InputKeyCode CRUMB_EQUALs = 61; /* = */
	constexpr InputKeyCode CRUMB_A = 65; /* A */
	constexpr InputKeyCode CRUMB_B = 66; /* B */
	constexpr InputKeyCode CRUMB_C = 67; /* C */
	constexpr InputKeyCode CRUMB_D = 68; /* D */
	constexpr InputKeyCode CRUMB_E = 69; /* E */
	constexpr InputKeyCode CRUMB_F = 70; /* F */
	constexpr InputKeyCode CRUMB_G = 71; /* G */
	constexpr InputKeyCode CRUMB_H = 72; /* H */
	constexpr InputKeyCode CRUMB_I = 73; /* I */
	constexpr InputKeyCode CRUMB_J = 74; /* J */
	constexpr InputKeyCode CRUMB_K = 75; /* K */
	constexpr InputKeyCode CRUMB_L = 76; /* L */
	constexpr InputKeyCode CRUMB_M = 77; /* M */
	constexpr InputKeyCode CRUMB_N = 78; /* N */
	constexpr InputKeyCode CRUMB_O = 79; /* O */
	constexpr InputKeyCode CRUMB_P = 80; /* P */
	constexpr InputKeyCode CRUMB_Q = 81; /* Q */
	constexpr InputKeyCode CRUMB_R = 82; /* R */
	constexpr InputKeyCode CRUMB_S = 83; /* S */
	constexpr InputKeyCode CRUMB_T = 84; /* T */
	constexpr InputKeyCode CRUMB_U = 85; /* U */
	constexpr InputKeyCode CRUMB_V = 86; /* V */
	constexpr InputKeyCode CRUMB_W = 87; /* W */
	constexpr InputKeyCode CRUMB_X = 88; /* X */
	constexpr InputKeyCode CRUMB_Y = 89; /* Y */
	constexpr InputKeyCode CRUMB_Z = 90; /* Z */
	constexpr InputKeyCode CRUMB_LEFT_BRACKET = 91; /* [ */
	constexpr InputKeyCode CRUMB_BACKSLASH = 92; /* \ */
	constexpr InputKeyCode CRUMB_RIGHT_BRACKET = 93; /* ] */
	constexpr InputKeyCode CRUMB_GRAVE_ACCENT = 96;  /* ` */
	constexpr InputKeyCode CRUMB_WORLD_1 = 161;
	constexpr InputKeyCode CRUMB_WORLD_2 = 162;
	constexpr InputKeyCode CRUMB_ESCAPE = 256;
	constexpr InputKeyCode CRUMB_ENTER = 257;
	constexpr InputKeyCode CRUMB_TAB = 258;
	constexpr InputKeyCode CRUMB_BACKSPACE = 259;
	constexpr InputKeyCode CRUMB_INSERT = 260;
	constexpr InputKeyCode CRUMB_DELETE = 261;
	constexpr InputKeyCode CRUMB_RIGHT = 262;
	constexpr InputKeyCode CRUMB_LEFT = 263;
	constexpr InputKeyCode CRUMB_DOWN = 264;
	constexpr InputKeyCode CRUMB_UP = 265;
	constexpr InputKeyCode CRUMB_PAGE_UP = 266;
	constexpr InputKeyCode CRUMB_PAGE_DOWN = 267;
	constexpr InputKeyCode CRUMB_HOME = 268;
	constexpr InputKeyCode CRUMB_END = 269;
	constexpr InputKeyCode CRUMB_CAPS_LOCK = 280;
	constexpr InputKeyCode CRUMB_SCROLL_LOCK = 281;
	constexpr InputKeyCode CRUMB_NUM_LOCK = 282;
	constexpr InputKeyCode CRUMB_PRINT_SCREEN = 283;
	constexpr InputKeyCode CRUMB_PAUSE = 284;
	constexpr InputKeyCode CRUMB_F1 = 290;
	constexpr InputKeyCode CRUMB_F2 = 291;
	constexpr InputKeyCode CRUMB_F3 = 292;
	constexpr InputKeyCode CRUMB_F4 = 293;
	constexpr InputKeyCode CRUMB_F5 = 294;
	constexpr InputKeyCode CRUMB_F6 = 295;
	constexpr InputKeyCode CRUMB_F7 = 296;
	constexpr InputKeyCode CRUMB_F8 = 297;
	constexpr InputKeyCode CRUMB_F9 = 298;
	constexpr InputKeyCode CRUMB_F10 = 299;
	constexpr InputKeyCode CRUMB_F11 = 300;
	constexpr InputKeyCode CRUMB_F12 = 301;
	constexpr InputKeyCode CRUMB_F13 = 302;
	constexpr InputKeyCode CRUMB_F14 = 303;
	constexpr InputKeyCode CRUMB_F15 = 304;
	constexpr InputKeyCode CRUMB_F16 = 305;
	constexpr InputKeyCode CRUMB_F17 = 306;
	constexpr InputKeyCode CRUMB_F18 = 307;
	constexpr InputKeyCode CRUMB_F19 = 308;
	constexpr InputKeyCode CRUMB_F20 = 309;
	constexpr InputKeyCode CRUMB_F21 = 310;
	constexpr InputKeyCode CRUMB_F22 = 311;
	constexpr InputKeyCode CRUMB_F23 = 312;
	constexpr InputKeyCode CRUMB_F24 = 313;
	constexpr InputKeyCode CRUMB_F25 = 314;
	constexpr InputKeyCode CRUMB_KP_0 = 320; /*KP means keypad*/
	constexpr InputKeyCode CRUMB_KP_1 = 321;
	constexpr InputKeyCode CRUMB_KP_2 = 322;
	constexpr InputKeyCode CRUMB_KP_3 = 323;
	constexpr InputKeyCode CRUMB_KP_4 = 324;
	constexpr InputKeyCode CRUMB_KP_5 = 325;
	constexpr InputKeyCode CRUMB_KP_6 = 326;
	constexpr InputKeyCode CRUMB_KP_7 = 327;
	constexpr InputKeyCode CRUMB_KP_8 = 328;
	constexpr InputKeyCode CRUMB_KP_9 = 329;
	constexpr InputKeyCode CRUMB_KP_DECIMAL = 330;
	constexpr InputKeyCode CRUMB_KP_DIVIDE = 331;
	constexpr InputKeyCode CRUMB_KP_MULTIPLY = 332;
	constexpr InputKeyCode CRUMB_KP_SUBTRACT = 333;
	constexpr InputKeyCode CRUMB_KP_ADD = 334;
	constexpr InputKeyCode CRUMB_KP_ENTER = 335;
	constexpr InputKeyCode CRUMB_KP_EQUAL = 336;
	constexpr InputKeyCode CRUMB_LEFT_SHIFT = 340;
	constexpr InputKeyCode CRUMB_LEFT_CONTROL = 341;
	constexpr InputKeyCode CRUMB_LEFT_ALT = 342;
	constexpr InputKeyCode CRUMB_LEFT_SUPER = 343;
	constexpr InputKeyCode CRUMB_RIGHT_SHIFT = 344;
	constexpr InputKeyCode CRUMB_RIGHT_CONTROL = 345;
	constexpr InputKeyCode CRUMB_RIGHT_ALT = 346;
	constexpr InputKeyCode CRUMB_RIGHT_SUPER = 347;
	constexpr InputKeyCode CRUMB_MENU = 348;

	constexpr InputActionCode CRUMB_RELEASED = 0;
	constexpr InputActionCode CRUMB_PRESSED = 1;
}