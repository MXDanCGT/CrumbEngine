#include "Core/Camera.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{

	Camera::Camera()
	{
		/*Defaults to y being the up direction*/
		//CameraUp = glm::vec3(0, 1, 0);

		//CameraPosition = glm::vec3(0, 0, 0);

		//CameraLookAt = glm::vec3(1, 0, 1); //Start us off looking kinda diagonally
	}


	//glm::mat4 Camera::GetViewMatrix()
	//{
	//	//return glm::lookAt(
	//	//	CameraPosition,
	//	//	CameraLookAt,
	//	//	CameraUp
	//	//);
	//}
}