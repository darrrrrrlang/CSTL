#include "function_object.h"
#include "../unility.h"
#include <list>
#include <algorithm>
#include <functional>

namespace
{
	class AddValue
	{
	private:
		int m_v;
	public:
		AddValue(int v)
		{
			m_v = v;
		}
		void operator()(int &elem) const
		{
			elem += m_v;
		}
	};
}

void TEST::test_simple_function_object()
{
	AddValue self_add5(5);
	AddValue self_add3(3);

	std::list<int> list{1,2,3,4,5};
	PRINT_ELEMENTES(list, "original list");

	std::for_each(list.begin(), list.end(), self_add3);
	PRINT_ELEMENTES(list, "add3");

	std::for_each(list.begin(), list.end(), self_add5);
	PRINT_ELEMENTES(list, "add5");
}

void TEST::test_predefined_function_object()
{
	std::list<int> list{ 1,2,3,4,5 };
	PRINT_ELEMENTES(list, "original list");

	std::transform(list.cbegin(), list.cend(), list.begin(), std::negate<int>());
	PRINT_ELEMENTES(list, "negate");

	std::transform(list.cbegin(), list.cend(), 
		list.cbegin(),
		list.begin(), std::multiplies<int>());
	PRINT_ELEMENTES(list, "multiplies");
}