#include "stream.h"

#include <iostream>
#include <bitset>
#include <complex>

using std::cout;
using std::endl;

void TEST::test_stream()
{
	cout << "TEST: test_stream" << endl;
	/* stream operator << */
	{
		cout << "TEST: <<" << endl;

		int i = 7;
		cout << "int i=" << i << endl;

		double d = 7.65;
		cout << "double d=" << d << endl;

		void *p = (void*)0x1234;
		cout << "void *p=" << p << endl;

		std::bitset<10> bitset(0x1 | 0x2 | 0x4 | 0x8 | 0x10);
		cout << "bitset<10>=" << bitset << endl;

		std::complex<float> c(-1, 3);
		cout << "complex<float>=" << c << endl;

		cout << endl;
	}
}