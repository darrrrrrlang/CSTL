#include "algorithm.h"

#include <vector>
#include <algorithm>
#include <iostream>

#include "../unility.h"

template <class T>
class MyPrint
{
public:
	void operator() (const T &ref)
	{
		std::cout << ref << " ";
	}
};

void TEST::test_algorithm()
{
	/* for_each */
	{
		MyPrint<int> print;
		std::vector<int> v{ 1,2,3,4,5 };

		std::cout << "for_each using functional object" << std::endl;
		std::for_each(v.cbegin(), v.cend(), print);
		std::cout << std::endl;

		std::cout << "for_each using Lambda" << std::endl;
		std::for_each(v.cbegin(), v.cend(), [](const int &ref) {std::cout << ref << " "; });
		std::cout << std::endl;
	}
	/* count */
	{
		std::vector<int> v{ 1,3,3,4,5,6,6 };

		std::cout << "count" << std::endl;
		std::cout << std::count(v.cbegin(), v.cend(), 3) << std::endl;
	}
}
