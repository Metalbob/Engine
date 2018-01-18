#pragma once

#ifndef ENGINE_EXP
#define ENGINE_EXP __declspec(dllexport)
#endif

#include "SceneManager.h"
#include "InputManager.h"

namespace Engine
{
	class Game
	{
		SceneManager * sceneManager;
		InputManager * inputManager;
		bool run = true;

	public:
		ENGINE_EXP Game();

		ENGINE_EXP void MainLoop();

		ENGINE_EXP void Quit();

		ENGINE_EXP ~Game();
	};
}