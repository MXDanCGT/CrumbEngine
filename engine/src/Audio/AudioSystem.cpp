
#include "Audio/AudioSystem.h"
#include "Core/CoreComponents.h"


namespace Crumb
{

	AudioSystem::AudioSystem()
	{
		m_AudioEngine = new ma_engine();
		InitSystem();
	}

	AudioSystem::~AudioSystem()
	{

	}

	void AudioSystem::InitSystem()
	{
		ma_engine_init(NULL, m_AudioEngine);
	}

	void AudioSystem::ShutdownSystem()
	{
		ma_engine_uninit(m_AudioEngine);
		if (m_AudioEngine)
			delete &m_AudioEngine;
	}

	void AudioSystem::process(ecs_hpp::registry& world, const FAudioRequests& evt)
	{
		//Irregardless of any components, we still need to go through this
		//Todo is this safe / good practice w/ ecs_hpp?

		for (auto& i : evt.Requests)
		{
			ma_sound* NewAudio = new ma_sound;

			ma_sound_config SoundConfig = ma_sound_config_init();

			//TEMP IGNORE WHAT WEVE DONE SO FAR JUST CHECKING TO SEE AUDIO IS PLAYING
			ma_result result = ma_engine_play_sound(m_AudioEngine, i.Filepath.c_str(), nullptr);

		}
	}
}