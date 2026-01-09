#include "Core/Core.h" //TODO is this the best way to structure shit?

namespace Crumb
{

	Core::Core(std::unique_ptr<Game> GivenGame)
	{
		m_Game = std::move(GivenGame);
	}

	Core::~Core()
	{

	}

	int Core::Init()
	{
		return m_Game->Init();
	}

	int Core::Run()
	{
		double DeltaTime = 0;
		auto LastTime = std::chrono::high_resolution_clock::now();

		while (!m_Game->ShouldCloseGame())
		{
			auto CurrentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> Delta = CurrentTime - LastTime;
			m_Game->Tick(Delta.count());

			LastTime = CurrentTime;
		}

		m_Game->Shutdown();
		return 0;
	}
}

