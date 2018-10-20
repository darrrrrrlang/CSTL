#pragma once

#include <string>
#include <iostream>

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
}