#pragma once

#include <map>

#include <SDL/SDL.h>

#include "KeyDelegate.h"

namespace Engine
{
	class InputManager
	{
		std::map<Uint32, KeyDelegate *> KeyInputDelegates;

		static InputManager * instance;
		InputManager();
		~InputManager();

		SDL_Event event;

	public:

		static InputManager * GetInstance();
		void DoInputs();
		void BindKey(Uint32 key, void (*func)());

		template<class T>
		void BindKey(Uint32 key, T * object, void (T::*method)())
		{
			if (KeyInputDelegates.find(key) == KeyInputDelegates.end())
				KeyInputDelegates[key] = new KeyDelegate();

			*(KeyInputDelegates[key]) += new KeyDelegate::MethodSubscriber<T>(object, method);
		}
	};
}