#include "stdafx.h"
#include "KeyDelegate.h"

#include <algorithm>

namespace Engine
{
	KeyDelegate& KeyDelegate::operator+=(const Subscriber * func)
	{
		toCall.push_back(func);
		return *this;
	}

	//KeyDelegate& KeyDelegate::operator-=(const Subscriber * func)
	//{
	//	std::remove(toCall.begin(), toCall.end(), func);
	//	return *this;
	//}

	void KeyDelegate::Invoke()
	{
		for (int i = 0; i < toCall.size(); i++)
		{
			toCall[i]->Call();
		}
	}
}