#include "stdafx.h"
#include "Entity.h"

namespace Engine
{
	Entity::Entity()
	{
	}

	void Entity::UpdateComponent()
	{
		if (children.size() > 0)
		{
			for (int i = 0; i < children.size(); i++)
			{
				children[i]->UpdateComponent();
			}
		}

		if (components.size() > 0)
		{
			for (int i = 0; i < components.size(); i++)
			{
				components[i]->Update();
			}
		}
	}

	Entity::~Entity()
	{
	}
}
