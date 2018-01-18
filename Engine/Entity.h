#pragma once

#include <list>

#include "Component.h"

namespace Engine
{
	class Entity
	{
		std::list<Component> components;
		std::list<Entity> children;

	public:
		Entity();
		virtual ~Entity();
	};
}