#include "stdafx.h"
#include "Scene.h"

namespace Engine
{
	Scene::Scene()
	{
	}

	void Scene::CallEntitiesScripts()
	{
		for (int i = 0; i < entities.size(); i++)
			entities[i]->UpdateComponent();
	}

	Scene::~Scene()
	{
	}
}