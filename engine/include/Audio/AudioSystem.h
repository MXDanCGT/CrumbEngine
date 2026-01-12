#pragma  once

#include "pch.h"

#include "AudioComponents.h"

#include "miniaudio.h"
#include "ecs.hpp/ecs.hpp"

namespace Crumb
{

	class AudioSystem : public ecs_hpp::system<FAudioRequests>
	{
	public:

		AudioSystem();
		~AudioSystem();

		void InitSystem();
		void ShutdownSystem();


		void process(ecs_hpp::registry& world, const FAudioRequests& evt);



	private:


		//This might be not "true" ecs, but its mvp at this point
		ma_engine* m_AudioEngine; //Think this is ok either way as this engine should be a singleton
		//CBA to build this library independent atm, miniaudio is platform independent either way
	};




}