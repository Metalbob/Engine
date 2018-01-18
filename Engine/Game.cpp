#include "stdafx.h"
#include "Game.h"

#include "Logger.h"

#include <SDL/SDL.h>

namespace Engine
{
	ENGINE_EXP Game::Game()
	{
		inputManager = InputManager::GetInstance();
		inputManager->BindKey<Game>(SDLK_ESCAPE, this, &Game::Quit);
		sceneManager = SceneManager::GetInstance();
	}

	ENGINE_EXP void Game::MainLoop()
	{
		while (run)
		{
			inputManager->DoInputs();
			sceneManager->UpdateCurrentScene();
		}
	}

	ENGINE_EXP void Game::Quit()
	{
		run = false;
	}

	ENGINE_EXP Game::~Game()
	{
	}
}
