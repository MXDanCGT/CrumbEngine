#pragma once

#include "pch.h"

//#include "glm/glm.hpp"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace Crumb
{
	/*
	* Cameras are what we view the world through - and what we form our view matrix on
	*/
	class Camera
	{
	public:

		Camera(float FOV = 90.f, float NearClip = 0.1f, float FarClip = 100.f);

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjMatrix();

		/*Move our cameras position*/
		void MoveCamera_ForwardBackward(float FBSpeed);
		void MoveCamera_UpDown(float UDSpeed); /*UpDown uses world axis, hence it is different...*/
		void MoveCamera_LeftRight(float LRSPeed);


		inline glm::vec3 GetPosition() { return m_CameraPosition; }
		void SetPosition(glm::vec3 GivenPos) { m_CameraPosition = GivenPos; }


		inline glm::vec3 GetDirection() { return m_CameraDirection; }
		void SetDirection(glm::vec3 GivenDir) { m_CameraDirection = GivenDir; }

		inline glm::vec3 GetRight() { return m_CameraRight; }
		inline void SetRight(glm::vec3 GivenRight) { m_CameraRight = GivenRight; }


		void RotateCamera(glm::vec3 GivenRot);

	protected:

		glm::vec3 m_CameraPosition;
		glm::vec3 m_CameraDirection;
		glm::vec3 m_CameraUp;

		glm::vec3 m_CameraRight;

		//ROLL, PITCH, YAW
		/*Wheres our camera facing? default (i.e.: 0,0,0) is looking in direction (1,0,0)*/
		glm::vec3 m_CameraRotation;

		/*Field of view of the camera*/
		float m_FOV;

		float m_NearClip;
		float m_FarClip;

	};

}