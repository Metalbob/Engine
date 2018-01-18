#pragma once

#ifndef ENGINE_EXP
#define ENGINE_EXP __declspec(dllexport)
#endif

#include "Scene.h"
#include "InputManager.h"

namespace Engine
{
	class Game
	{
		Scene currentScene;
		InputManager * inputManager;
		bool run = true;

	public:
		ENGINE_EXP Game();

		ENGINE_EXP void MainLoop();

		ENGINE_EXP void Quit();

		ENGINE_EXP ~Game();
	};

	void Func();
}