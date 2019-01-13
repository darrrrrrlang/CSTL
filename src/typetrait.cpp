
#include "typetrait.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename _T>
void TestType()
{
	cout << "is_void=" << std::is_void<_T>() << endl;
	cout << "is_integral=" << std::is_integral<_T>() << endl;
	cout << "is_floating_point=" << std::is_floating_point<_T>() << endl;
	cout << "is_arithmetic=" << std::is_arithmetic<_T>() << endl;
	cout << "is_signed=" << std::is_signed<_T>() << endl;
	cout << "is_unsigned=" << std::is_unsigned<_T>() << endl;
	cout << "is_const=" << std::is_const<_T>() << endl;
	cout << "is_volatile=" << std::is_volatile<_T>() << endl;
	cout << "is_array=" << std::is_array<_T>() << endl;
	cout << "is_enum=" << std::is_enum<_T>() << endl;
	cout << "is_union=" << std::is_union<_T>() << endl;
	cout << "is_class=" << std::is_class<_T>() << endl;
	cout << "is_function=" << std::is_function<_T>() << endl;
	cout << "is_reference=" << std::is_reference<_T>() << endl;
	cout << "is_lvalue_reference=" << std::is_lvalue_reference<_T>() << endl;
	cout << "is_pointer=" << std::is_pointer<_T>() << endl;
	cout << "is_member_pointer=" << std::is_member_pointer<_T>() << endl;
	cout << "is_member_object_pointer=" << std::is_member_object_pointer<_T>() << endl;
	cout << "is_member_function_pointer=" << std::is_member_function_pointer<_T>() << endl;
	cout << "is_fundamental=" << std::is_fundamental<_T>() << endl;
	cout << "is_scalar=" << std::is_scalar<_T>() << endl;
	cout << "is_object=" << std::is_object<_T>() << endl;
	cout << "is_compound=" << std::is_compound<_T>() << endl;
	cout << "is_trivial=" << std::is_trivial<_T>() << endl;
	cout << "is_trivially_copyable=" << std::is_trivially_copyable<_T>() << endl;
	cout << "is_standard_layout=" << std::is_standard_layout<_T>() << endl;
	cout << "is_pod=" << std::is_pod<_T>() << endl;
	cout << "is_literal_type=" << std::is_literal_type<_T>() << endl;
}

void TEST::test_typetrait_common()
{
	cout << "TEST test_typetrait" << endl;

	cout << "unsigned short" << endl;
	TestType<unsigned short>();
	cout << endl;

	cout << "double" << endl;
	TestType<double>();
	cout << endl;

	cout << endl;
}

