
#include "algorithm.h"

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

void TEST::test_min_max_find_sort_reverse()
{
	vector<int> v{ 3,6,4,1,8,6 };

	cout << "original array : " << endl;
	for (auto const& r : v)
	{
		cout << r << " ";
	}
	cout << endl;

	auto const& it_min = min_element(v.cbegin(), v.cend());
	cout << "min=" << *it_min << endl;

	auto const& it_max = max_element(v.cbegin(), v.cend());
	cout << "max=" << *it_max << endl;

	cout << "sort" << endl;
	sort(v.begin(), v.end());

	for (auto const& r : v)
	{
		cout << r << " ";
	}
	cout << endl;

	cout << "find element 6 and reverse all after it" << endl;
	auto & pos_third = find(v.begin(), v.end(), 6);

	reverse(pos_third, v.end());

	for (auto const& r : v)
	{
		cout << r << " ";
	}
	cout << endl;
}

void TEST::test_compare_copy()
{
	vector<int> v{ 1,3,5,7 };
	list<int> l{ 1,3,5,7 };
	
	cout << "vector is :" << endl;
	for (auto const& r : v) 
	{
		cout << r << " ";
	}
	cout << endl;

	cout << "list is :" << endl;
	for (auto const& r : l)
	{
		cout << r << " ";
	}
	cout << endl;

	cout << "test if they are equal:" << endl;
	if (equal(v.begin(), v.end(), l.begin()))
	{
		cout << "vector and list are equal" << endl;
	}
	else
	{
		cout << "vector and list are not equal" << endl;
	}
	
	cout << "modify v" << endl;
	v[3] = 5;
	for (auto const& r : v)
	{
		cout << r << " ";
	}
	cout << endl;

	cout << "copy v to l" << endl;
	copy(v.begin(), v.end(), l.begin());

	cout << "l:" << endl;
	for (auto const& r : v)
	{
		cout << r << " ";
	}
	cout << endl;
}