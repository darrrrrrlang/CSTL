
#include "container.h"
#include "algorithm.h"
#include "iterator_adaptor.h"
#include "functional_algorithm_parameter.h"
#include "function_object.h"

#include <iostream>

struct array
{
	int array[12];
};

int main()
{
	//TEST::test_min_max_find_sort_reverse();
	//TEST::test_compare_copy();
	//TEST::test_insert_iterator();
	//TEST::test_stream_iterator();
	//TEST::test_reverse_iterator();
	//TEST::test_foreach();
	//TEST::test_transform();
	//TEST::test_find_if();
	//TEST::test_sort_self_defined();
	//TEST::test_simple_function_object();
	//TEST::test_predefined_function_object();
	//TEST::test_array();
	//TEST::test_vector();
	//TEST::test_list();
	//TEST::test_set();
	TEST::test_map();
	return 0;
}