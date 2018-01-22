#include "stdafx.h"
#include "Logger.h"

#include <iostream>

namespace Engine
{
	ENGINE_EXP void Logger::Log(const char * msg)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << msg << std::endl;
	}

	ENGINE_EXP void Logger::LogWarning(const char * msg)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << msg << std::endl;
	}

	ENGINE_EXP void Logger::LogError(const char * msg)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << msg << std::endl;
	}
}
