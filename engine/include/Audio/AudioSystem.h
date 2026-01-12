#pragma  once

#include "pch.h"

#include "miniaudio.h"


namespace Crumb
{

	class AudioSystem
	{
	public:

		AudioSystem();
		~AudioSystem();


		void InitSystem();
		void ShutdownSystem();






	private:


		//This might be not "true" ecs, but its mvp at this point
		ma_engine* m_AudioEngine; //Think this is ok either way as this engine should be a singleton
		//CBA to build this library independent atm, miniaudio is platform independent either way

	};




}