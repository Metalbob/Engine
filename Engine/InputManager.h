#pragma once

#include <map>

#include <SDL/SDL.h>

#include "KeyDelegate.h"

namespace Engine
{
	class InputManager
	{
		std::map<Uint32, KeyDelegate *> KeyInputDelegatesKeyDown;
		std::map<Uint32, KeyDelegate *> KeyInputDelegatesKeyUp;

		static InputManager * instance;
		InputManager();
		~InputManager();

		SDL_Event event;

	public:

		static InputManager * GetInstance();
		void DoInputs();
		void BindKey(Uint32 key, SDL_EventType type, void (*func)());

		template<class T>
		void BindKey(Uint32 key, SDL_EventType type, T * object, void (T::*method)())
		{
			if (type == SDL_EventType::SDL_KEYDOWN)
			{
				if (KeyInputDelegatesKeyDown.find(key) == KeyInputDelegatesKeyDown.end())
					KeyInputDelegatesKeyDown[key] = new KeyDelegate();

				*(KeyInputDelegatesKeyDown[key]) += new KeyDelegate::MethodSubscriber<T>(object, method);
			}
			if (type == SDL_EventType::SDL_KEYUP)
			{
				if (KeyInputDelegatesKeyUp.find(key) == KeyInputDelegatesKeyUp.end())
					KeyInputDelegatesKeyUp[key] = new KeyDelegate();

				*(KeyInputDelegatesKeyUp[key]) += new KeyDelegate::MethodSubscriber<T>(object, method);
			}
		}
	};
}