#include "algorithm.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

#include "../unility.h"

void TEST::test_algorithm()
{
	/* for_each */
	{
		std::cout << "TEST: for_each" << std::endl;

		std::vector<int> v{ 1,2,3,4,5 };
		PRINT_ELEMENTES(v, "original v");

		std::cout << "for_each print" << std::endl;
		std::for_each(v.cbegin(), v.cend(), [](const int &ref) {std::cout << ref << " "; });
		std::cout << std::endl;

		std::cout << "for_each modify elements" << std::endl;
		std::for_each(v.begin(), v.end(), [](int &ref) {ref += 1; });
		PRINT_ELEMENTES(v, "after modifying");

		std::cout << std::endl;
	}
	/* count */
	{
		std::cout << "TEST: count" << std::endl;
		std::vector<int> v{ 1,3,3,4,5,6,6 };
		PRINT_ELEMENTES(v, "original vector");

		std::cout << "count 3" << std::endl;
		std::cout << std::count(v.cbegin(), v.cend(), 3) << std::endl;

		std::cout << "count_if over 3 using lambda" << std::endl;
		std::cout << std::count_if(v.cbegin(), v.cend(), [](const int &ref)->bool {return ref > 3; });

		std::cout << std::endl;
	}
	/* min_element & max_element & minmax_element */
	{
		std::cout << "TEST: min_element" << std::endl;

		std::vector<int> v{ 5,3,8,8,6 };
		PRINT_ELEMENTES(v, "original vector");
		std::cout << "*min_element(v)=" << *std::min_element(v.cbegin(), v.cend()) << std::endl;
		std::cout << "*min_element(v, comp)=" << *std::min_element(v.cbegin(), v.cend(),
			[](const int &ref_a, const int &ref_b)->bool {return ref_a < ref_b; }) << std::endl;
		std::cout << "*max_element(v)=" << *std::max_element(v.cbegin(), v.cend()) << std::endl;
		std::cout << "*max_element(v, comp)=" << *std::max_element(v.cbegin(), v.cend(),
			[](const int &ref_a, const int &ref_b)->bool {return ref_a < ref_b; }) << std::endl;
		auto it_minmax_1 = std::minmax_element(v.cbegin(), v.cend());
		auto it_minmax_2 = std::minmax_element(v.cbegin(), v.cend(),
			[](const int &ref_a, const int &ref_b)->bool {return ref_a < ref_b; });
		std::cout << "*minmax_element(v).first=" << *(it_minmax_1.first) << std::endl;
		std::cout << "*minmax_element(v).second=" << *(it_minmax_1.second) << std::endl;
		std::cout << "*minmax_element(v, comp).first=" << *(it_minmax_2.first) << std::endl;
		std::cout << "*minmax_element(v, comp).second=" << *(it_minmax_2.second) << std::endl;
		std::cout << std::endl;
	}
	/* find & find_if & find_if_not */
	{
		std::cout << "TEST: find" << std::endl;

		std::vector<int> v{ 5,3,8,8,6 };
		PRINT_ELEMENTES(v, "original vector");
		std::cout << "*find(v,3)=" << *std::find(v.cbegin(), v.cend(), 3) << std::endl;
		std::cout << "*find_if(v, >5)=" << *std::find_if(v.cbegin(), v.cend(), [](const int &ref)->bool {return ref > 5; }) << std::endl;
		std::cout << "*find_if_not(v, >5)=" << *std::find_if_not(v.cbegin(), v.cend(), [](const int &ref)->bool {return ref > 5; }) << std::endl;
		std::cout << std::endl;
	}
	/* search_n */
	{
		std::cout << "TEST: search_n" << std::endl;

		std::vector<int> v{ 4,5,7,7,7,5,2,2,3 };
		PRINT_ELEMENTES(v, "original vector");
		std::cout << "*search_n(v.cbegin(), v.cend(), 2, 7)=" << *std::search_n(v.cbegin(), v.cend(), 2, 7) << std::endl;
		std::cout << "*search_n(v.cbegin(), v.cend(), 2, 0, (elem+value)<5 = " <<
			*std::search_n(v.cbegin(), v.cend(), 2, 0, [](const int &ref_elem, const int &ref_value)->bool {return ref_elem + ref_value < 5; }) \
			<< std::endl;
		std::cout << std::endl;
	}
	/* search */
	{
		std::cout << "TEST: search" << std::endl;

		std::vector<int> v{ 1,6,7,8,2,3,4,9 };
		std::vector<int> v2{ 8,2,3 };
		PRINT_ELEMENTES(v, "v: ");
		PRINT_ELEMENTES(v2, "v2: ");
		std::cout << "*search(v.cbegin(), v.cend(), v2.cbegin(), v2.cend())=" <<
			*std::search(v.cbegin(), v.cend(), v2.cbegin(), v2.cend()) << std::endl;
		v2 = { 7,1,2 };
		PRINT_ELEMENTES(v2, "v2:");
		std::cout << "*search(v.cbegin(), v.cend(), v2.cbegin(), v2.cend(), op(ele-1==value))=" <<
			*std::search(v.cbegin(), v.cend(), v2.cbegin(), v2.cend(),
				[](const int &ref_elem, const int &ref_value)->bool {return ref_elem - 1 == ref_value; })
			<< std::endl;
		std::cout << std::endl;
	}
	/* find_end */
	{
		std::cout << "TEST: find_end" << std::endl;

		std::cout << "find_end finds the last section while search finds the first" << std::endl;
		std::cout << std::endl;
	}
	/* find_first_of */
	{
		std::cout << "TEST: find_first_of" << std::endl;

		std::vector<int> v{ 23,67,53,88,1,78 };
		std::vector<int> v2{ 99,14,55,53 };
		PRINT_ELEMENTES(v, "v:");
		PRINT_ELEMENTES(v2, "v2:");

		std::cout << "*find_first_of(v.cbegin(), v.cend(), v2.cbegin(), v2.cend())=" <<
			*std::find_first_of(v.cbegin(), v.cend(), v2.cbegin(), v2.cend()) << std::endl;
		std::cout << "*find_first_of(v.cbegin(), v.cend(), v2.cbegin(), v2.cend(), op(a + b == 100))=" <<
			*std::find_first_of(v.cbegin(), v.cend(), v2.cbegin(), v2.cend(),
				[](const int &ref_elem, const int &ref_value)->bool {return ref_elem + ref_value == 100; }) << std::endl;
		std::cout << std::endl;
	}
	/* adjacent_find */
	{
		std::cout << "TEST: adjacent_find" << std::endl;

		std::vector<int> v{ 1,3,5,7,7,9, 10 };
		PRINT_ELEMENTES(v, "v:");
		std::cout << "*adjacent_find(v.cbegin(), v.cend())=" <<
			*std::adjacent_find(v.cbegin(), v.cend()) << std::endl;
		std::cout << "*adjacent_find(v.cbegin(), v.cend(), op(a + 1 == b))=" <<
			*std::adjacent_find(v.cbegin(), v.cend(),
				[](const int &ref_elem, const int &ref_value)->bool {return ref_elem + 1 == ref_value; }) << std::endl;
		std::cout << std::endl;
	}
	/* equal */
	{
		std::cout << "TEST: equal" << std::endl;

		std::vector<int> v{ 0,1,2,3,4,5,6,7,8,9 };
		std::vector<int> v2{ 0,1,2,3,4,5,6,7,8,9,10,11 };
		std::vector<int> v3{ 1,2,3,4,5,6,7,8,9,10 };
		PRINT_ELEMENTES(v, "v:");
		PRINT_ELEMENTES(v2, "v2:");
		PRINT_ELEMENTES(v3, "v3:");

		std::cout << "equal(v.cbegin(), v.cend(), v1.cbegin())=" <<
			std::equal(v.cbegin(), v.cend(), v2.cbegin()) << std::endl;
		std::cout << "equal(v.cbegin(), v.cend(), v3.cbegin(), op(a+1==b))=" <<
			std::equal(v.cbegin(), v.cend(), v3.cbegin(),
				[](const int &ref_elem, const int &ref_value)->bool {return ref_elem + 1 == ref_value; }) << std::endl;
		std::cout << std::endl;
	}
	/* is_permutation */
	{
		std::cout << "TEST: is_permutation" << std::endl;

		std::vector<int> v{ 1,2,3,4,5 };
		std::vector<int> v2{ 2,3,1,5,4 };
		std::vector<int> v3{ 6,5,4,3,2 };
		PRINT_ELEMENTES(v, "v:");
		PRINT_ELEMENTES(v2, "v2:");
		PRINT_ELEMENTES(v3, "v3:");
		std::cout << "is_permutation(v.cbegin(), v.cend(), v2.cbegin())=" <<
			std::is_permutation(v.cbegin(), v.cend(), v2.cbegin()) << std::endl;
		std::cout << "is_permutation(v.cbegin(), v.cend(), v3.cbegin(), op(a+1==b))=" <<
			std::is_permutation(v.cbegin(), v.cend(), v3.cbegin(),
				[](const int &ref_elem, const int &ref_value)->bool {return ref_elem + 1 == ref_value; }) << std::endl;
		std::cout << std::endl;
	}
}
