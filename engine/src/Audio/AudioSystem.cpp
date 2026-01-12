#include "Audio/AudioSystem.h"

namespace Crumb
{

	void AudioSystem::InitSystem()
	{
		ma_engine_init(NULL, m_AudioEngine);
	}


	void AudioSystem::ShutdownSystem()
	{
		ma_engine_uninit(m_AudioEngine);
		if (m_AudioEngine)
			delete m_AudioEngine;
	}
}