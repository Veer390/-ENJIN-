#pragma once
#include<iostream>

#include<functional>
#include<memory>

#include<string>
#include<vector>
#include<unordered_map>

namespace EngineCore
{
	namespace DataStructures
	{
		class String_Switcher
		{
		public:
			std::function<void()>& Case(std::wstring str)
			{
				return Map[str];
			}
			std::function<void()>& Default()
			{
				return Def;
			}
			void operator[](std::wstring Query)
			{
				auto i = Map.find(Query);
				if (i != Map.end())
				{
					i->second();
				}
				else
				{
					Def();
				}
			}
		private:
			std::unordered_map<std::wstring, std::function<void()>> Map;
			std::function<void()> Def = []() {};
		};

	}
}