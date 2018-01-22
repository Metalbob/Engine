// EngineTest.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>

#include <SDL\SDL.h>
#undef main

#include "Window.h"
#include "Game.h"

int main()
{
	Engine::Window w = Engine::Window();

	Engine::Game g = Engine::Game();

	g.MainLoop(&w);

	return 0;
}