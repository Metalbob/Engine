#pragma once

#include <vector>

namespace Engine
{
	class KeyDelegate
	{
		class Subscriber
		{
		public:
			Subscriber() = default;
			~Subscriber() = default;

			virtual void Call() const = 0;
		};

		std::vector<const Subscriber *> toCall;

	public:
		KeyDelegate() = default;
		~KeyDelegate() = default;

		KeyDelegate& operator+=(const Subscriber * func);
		//KeyDelegate& operator-=(const Subscriber * func);

		virtual void Invoke();

		class FunctionSubscriber : public Subscriber
		{
			void(*function)();

		public:
			FunctionSubscriber(void(*function)()) : function{ function } {}

			void Call() const override
			{
				function();
			}
		};

		template<class T>
		class MethodSubscriber : public Subscriber
		{
			T * object;
			void (T::*method)();

		public:
			MethodSubscriber(T * object, void (T::*method)()) : object{ object }, method{ method } {}

			void Call() const override
			{
				(*object.*method)();
			}
		};
	};
}