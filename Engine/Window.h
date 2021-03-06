#pragma once

#ifndef ENGINE_EXP
#define ENGINE_EXP __declspec(dllexport)
#endif

#include <SDL/SDL.h>

namespace Engine
{
	class Window
	{
		char * title;
		unsigned int posX;
		unsigned int posY;
		unsigned int width;
		unsigned int height;

	public:

		enum EWindowMode
		{
			FULLSCREEN,
			WINDOWED_CENTER,
			WINDOWED_TOP_LEFT
		};

		SDL_Window * window;
		SDL_GLContext context;

		ENGINE_EXP Window();
		ENGINE_EXP Window(const char * title, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height);
		ENGINE_EXP Window(const char * title, unsigned int width, unsigned int height, EWindowMode mode);
		ENGINE_EXP ~Window();
	};
}