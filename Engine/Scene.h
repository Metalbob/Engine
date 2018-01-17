#pragma once

#include <list>

#include "Entity.h"

namespace Engine
{
	class Scene
	{
		std::list<Entity> entities;

	public:
		Scene();
		~Scene();
	};
}