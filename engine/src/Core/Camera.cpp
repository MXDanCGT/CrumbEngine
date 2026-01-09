#include "Core/Camera.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crumb
{

	Camera::Camera(float FOV, float NearClip, float FarClip)
	{

		m_CameraPosition = glm::vec3(4, 3, 3);

		m_CameraDirection = m_CameraDirection = glm::normalize(glm::vec3(0, 0, 0) - m_CameraPosition);; //Start us off looking kinda diagonally

		/*Defaults to y being the up direction*/
		m_CameraUp = glm::vec3(0, 1, 0);
		m_CameraRight = glm::normalize(glm::cross(m_CameraDirection, glm::vec3(0,1,0)));
		m_FOV = FOV;
		m_NearClip = NearClip;
		m_FarClip = FarClip;
	}


	glm::mat4 Camera::GetViewMatrix()
	{
		glm::mat4 View = glm::lookAt(
			m_CameraPosition, 
			m_CameraPosition + m_CameraDirection, // and looks at the origin
			m_CameraUp  // Head is up (set to 0,-1,0 to look upside-down)
		);

		return View;
	}

	glm::mat4 Camera::GetProjMatrix()
	{
		return glm::perspective(
			glm::radians(m_FOV),
			100.f/100.f, 
			m_NearClip, m_FarClip
		);
	}
	//TODO ALLOW OVERRIDING FOR SPECIFIC CAMERA MOVEMENT...
	void Camera::MoveCamera_ForwardBackward(float FBSpeed)
	{
		m_CameraPosition += FBSpeed * m_CameraDirection;
	}

	void Camera::MoveCamera_LeftRight(float LRSpeed)
	{
		m_CameraPosition += LRSpeed * glm::normalize(glm::cross(m_CameraDirection, m_CameraUp));
	}
	void Camera::MoveCamera_UpDown(float UDSpeed)
	{
		m_CameraPosition += m_CameraUp * UDSpeed;
	}
}