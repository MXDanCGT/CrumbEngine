#pragma once

#include "pch.h"

//#include "glm/glm.hpp"

namespace Crumb
{
	/*
	* Cameras are what we view the world through - and what we form our view matrix on
	*/
	class Camera
	{
	public:

		Camera();

		//glm::mat4 GetViewMatrix();

	protected:

		//glm::vec3 CameraPosition;
		//glm::vec3 CameraLookAt;
		//glm::vec3 CameraUp;

	};

}