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

		while (!m_Game->ShouldCloseGame())
		{
			/*Handle our BTS tick stuff*/
			m_Game->Tick(DeltaTime);
		}
		m_Game->Shutdown();
		return 0;
	}
}

