#include "stdafx.h"
#include "SceneManager.h"


namespace Engine
{
	SceneManager * SceneManager::instance = nullptr;

	SceneManager::SceneManager()
	{
	}

	SceneManager * SceneManager::GetInstance()
	{
		if (instance == nullptr)
			instance = new SceneManager();

		return instance;
	}

	void SceneManager::UpdateCurrentScene()
	{

	}

	SceneManager::~SceneManager()
	{
	}
}