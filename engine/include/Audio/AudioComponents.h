#pragma once

#include "miniaudio.h"

namespace Crumb
{
	/*
	* Another feature struct used when adding systems to a registry (e.g.: our game world) - im not entirely sure what they do, but are utilised in ecs_hpps demos so Im going to follow suit
	*/
	struct FAudioFeature
	{
	};

	/*
	* An audio request, coming in to the audio system and being played
	*/
	struct FAudioRequest
	{
		FAudioRequest() {};

		FAudioRequest(std::string path)
		{
			Filepath = path;
			//TODO OTHER VARS
		}

		std::string Filepath;
		float Volume;
		bool bLoop;

	};

	/*
	* ECS audio component, we will create sound "entities" and look through these
	*/
	struct FCAudioPersistent
	{
		ma_sound sound;
		bool bPlaying = false;
	};

	//We will automatically handle spatial audio dpending on if or if not the entity has a transform component...

	/*
	* The audio  requests incoming to our audio system...
	*/
	struct FAudioRequests
	{
		std::vector<FAudioRequest> Requests;

		void AddRequest(const char* FileRequest)
		{
			FAudioRequest NewRequest(FileRequest);
			Requests.push_back(NewRequest);
		}
	};
}