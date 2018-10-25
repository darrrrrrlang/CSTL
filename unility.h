#pragma once

#include <string>
#include <iostream>
#include <map>

namespace TEST
{
	template <typename T>
	void PRINT_ELEMENTES(const T& container, const std::string & optstr = "")
	{
		std::cout << optstr << std::endl;
		for (const auto& r : container)
		{
			std::cout << r << " ";
		}
		std::cout << std::endl;
	}

	template <typename KEY, typename VALUE>
	void PRINT_ELEMENTES(const std::map<KEY, VALUE> container, const std::string & optstr = "")
	{
		std::cout << optstr << std::endl;
		for (const auto& r : container)
		{
			std::cout << r.first << " " << r.second << "     ";
		}
		std::cout << std::endl;
	}
}