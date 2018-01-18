#pragma once

#include <vector>

#include "Component.h"

namespace Engine
{
	class Entity
	{
		std::vector<Component *> components;
		std::vector<Entity *> children;

	public:
		Entity();
		virtual ~Entity();

		void UpdateComponent();
	};
}