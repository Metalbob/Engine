#pragma once

#include "Scene.h"

namespace Engine
{
	class SceneManager
	{
		static SceneManager * instance;

		Scene * currentScene;

		SceneManager();
		~SceneManager();

	public:

		static SceneManager * GetInstance();

		void UpdateCurrentScene();
	};
}

