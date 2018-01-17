// EngineTest.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <SDL\SDL.h>
#undef main

#include "Window.h"


int main()
{
	Engine::Window w = Engine::Window();
	bool run = true;
	
	SDL_Event event;

	while (run)
	{
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					run = false;
					break;

				default:break;
			}
		}
	}

	return 0;
}

