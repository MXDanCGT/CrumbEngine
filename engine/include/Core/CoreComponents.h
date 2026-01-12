#pragma once


#include "glm/glm.hpp"

/*
* TODO REINTRODUCE LIBRARY AGNOSTISIM, ONLY GLM VERSION EXISTS ATM
*/
namespace Crumb
{
	//we use the C prefix to indicate components... so FC -> (Struct)(Component)

	//Empty struct, used as a marker for "dont run any systems on this...
	struct FCDisabled
	{ };



	
	/*Decided to split up transform, not all things that have a position need a rotation etc.*/
	struct FCPosition
	{
		//Good to keep this renderer agnostic...
		float* Position; //XYZ
	};


	struct FCRotation
	{
		float* Rotation; //ROLL PITCH YAW
	};



}