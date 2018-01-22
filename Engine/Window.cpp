#include "stdafx.h"
#include "Window.h"

#include <iostream>

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "Logger.h"

namespace Engine
{

	ENGINE_EXP Window::Window() : Window("Engine window", 1280, 720, EWindowMode::WINDOWED_CENTER)
	{}

	ENGINE_EXP Window::Window(const char * title, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height)
	{
		SDL_Init(SDL_INIT_VIDEO);
		this->posX = posX;
		this->posY = posY;
		this->width = width;
		this->height = height;


		window = SDL_CreateWindow(title, posX + 7, posY + 30, width, height, SDL_WINDOW_OPENGL);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		context = SDL_GL_CreateContext(window);
		if (context == nullptr)
		{
			Logger::LogError("Failed to create context");
		}
		else
		{
			glewExperimental = GL_TRUE;
			GLuint glewError = glewInit();
			if (glewError != GLEW_OK)
			{
				Logger::LogError("Error initializing GLEW! ");
				Logger::LogError((char *)glewGetErrorString(glewError));
			}
		}
	}

	ENGINE_EXP Window::Window(const char * title, unsigned int width, unsigned int height, EWindowMode mode)
	{
		SDL_Init(SDL_INIT_VIDEO);

		this->width = width;
		this->height = height;

		Uint32 sdlFlags = SDL_WINDOW_OPENGL;

		switch (mode)
		{
		case EWindowMode::WINDOWED_CENTER:
			SDL_DisplayMode DM;
			if (SDL_GetCurrentDisplayMode(0, &DM) != 0)
				std::cout << "Failed to get display mode" << std::endl;
			posX = DM.w / 2 - width / 2 - 3;
			posY = DM.h / 2 - height / 2 - 15;
			break;
		case EWindowMode::WINDOWED_TOP_LEFT:
			posX = 0;
			posY = 0;
			break;
		case EWindowMode::FULLSCREEN:
			sdlFlags |= SDL_WINDOW_FULLSCREEN;
			break;
		default:
			break;
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		window = SDL_CreateWindow(title, posX, posY, width, height, sdlFlags);

		context = SDL_GL_CreateContext(window);

		if (context == nullptr)
		{
			Logger::LogError("Failed to create context");
		}
		else
		{
			glewExperimental = GL_TRUE;
			GLenum glewError = glewInit();
			if (glewError != GLEW_OK)
			{
				Logger::LogError("Error initializing GLEW! ");
				Logger::LogError((char *)glewGetErrorString(glewError));
			}
		}
	}



	ENGINE_EXP Window::~Window()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

}
