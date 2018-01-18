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
				if (KeyInputDelegates.find(event.key.keysym.sym) != KeyInputDelegates.end())
					KeyInputDelegates[event.key.keysym.sym]->Invoke();
				break;

			default:break;
			}
		}
	}

	void InputManager::BindKey(Uint32 key, void(*func)())
	{
		if (KeyInputDelegates.find(key) == KeyInputDelegates.end())
			KeyInputDelegates[key] = new KeyDelegate();

		*(KeyInputDelegates[key]) += new KeyDelegate::FunctionSubscriber(func);
	}
}