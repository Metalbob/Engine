#pragma once

#include <vector>

#include "Entity.h"

namespace Engine
{
	class Scene
	{
		std::vector<Entity *> entities;

	public:

		void CallEntitiesScripts();

		Scene();
		~Scene();
	};
}