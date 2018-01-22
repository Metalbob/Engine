#include "stdafx.h"
#include "InputManager.h"
#include "Logger.h"


#include <iostream>

namespace Engine
{
	InputManager * InputManager::instance = nullptr;

	InputManager::InputManager()
	{

	}


	InputManager::~InputManager()
	{
	}

	InputManager* InputManager::GetInstance()
	{
		if (instance == nullptr)
			instance = new InputManager();

		return instance;
	}

	void InputManager::DoInputs()
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (KeyInputDelegatesKeyDown.find(event.key.keysym.sym) != KeyInputDelegatesKeyDown.end())
					KeyInputDelegatesKeyDown[event.key.keysym.sym]->Invoke();
				break;
			case SDL_KEYUP:
				if (KeyInputDelegatesKeyUp.find(event.key.keysym.sym) != KeyInputDelegatesKeyUp.end())
					KeyInputDelegatesKeyUp[event.key.keysym.sym]->Invoke();
				break;
			default:
				break;
			}
		}
	}

	void InputManager::BindKey(Uint32 key, SDL_EventType type, void(*func)())
	{
		if (type == SDL_EventType::SDL_KEYDOWN)
		{
			if (KeyInputDelegatesKeyDown.find(key) == KeyInputDelegatesKeyDown.end())
				KeyInputDelegatesKeyDown[key] = new KeyDelegate();

			*(KeyInputDelegatesKeyDown[key]) += new KeyDelegate::FunctionSubscriber(func);
		}
		if (type == SDL_EventType::SDL_KEYUP)
		{
			if (KeyInputDelegatesKeyUp.find(key) == KeyInputDelegatesKeyUp.end())
				KeyInputDelegatesKeyUp[key] = new KeyDelegate();

			*(KeyInputDelegatesKeyUp[key]) += new KeyDelegate::FunctionSubscriber(func);
		}
	}
}