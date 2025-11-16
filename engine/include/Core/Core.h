#pragma once

#include "Game/Game.h"

namespace Crumb
{

	/*
	* CORE is app initialisation and running that is completely abstracted from our application programmer
	*/
	class Core
	{
	public:

		Core(std::unique_ptr<Game> GivenGame);

		~Core();

		/*Parts of the loop abstracted from the application programmer*/
		int Run();

		/*Initialise our managers / all the systems we may need*/
		int Init();


	private:

		std::unique_ptr<Game> m_Game;
	};


}