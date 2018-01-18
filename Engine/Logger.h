#pragma once

#ifndef ENGINE_EXP
#define ENGINE_EXP __declspec(dllexport)
#endif


namespace Engine
{
	class Logger
	{
	public:

		ENGINE_EXP static void Log(const char * msg);
		ENGINE_EXP static void LogWarning(const char * msg);
		ENGINE_EXP static void LogError(const char * msg);
	};
}

