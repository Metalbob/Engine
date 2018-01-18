#pragma once

namespace Engine
{
	class Component
	{
	public:
		Component();
		virtual ~Component();

		virtual void Start();
		virtual void Update();
	};
}

