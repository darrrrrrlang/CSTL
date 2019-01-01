#include "concurrency.h"

#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <chrono>

using std::cout;
using std::endl;

namespace 
{
	int doSomething(char c)
	{
		std::default_random_engine dre(c);
		std::uniform_int_distribution<int> id(10, 100);

		for (int i = 0; i < 10; ++i)
		{
			int t = id(dre);
			std::this_thread::sleep_for(std::chrono::milliseconds(t));
			cout.put(c).flush();
		}
		return c;
	}
	int func1()
	{
		return doSomething('.');
	}
	int func2()
	{
		return doSomething('+');
	}
	int func3()
	{
		throw 3;
		return 0;
	}
}

void TEST::test_async_future()
{
	cout << "TEST test_async_future" << endl;
	// normal
	{
		cout << "TEST default usage" << endl;
		std::future<int> result1(std::async(func1));
		std::future<int> result2(std::async(func2));
		int r1 = result1.get();
		int r2 = result2.get();
		cout << endl;
		cout << "result1=" << static_cast<char>(r1) << endl;
		cout << "result2=" << static_cast<char>(r2) << endl;
		cout << endl;
	}
	// async
	{
		cout << "TEST async usage" << endl;
		std::future<int> result1(std::async(std::launch::async, func1));
		std::future<int> result2(std::async(std::launch::async, func2));
		int r1 = result1.get();
		int r2 = result2.get();
		cout << endl;
		cout << "result1=" << static_cast<char>(r1) << endl;
		cout << "result2=" << static_cast<char>(r2) << endl;
		cout << endl;
	}
	// deferred
	{
		cout << "TEST deferred usage" << endl;
		std::future<int> result1(std::async(std::launch::deferred, func1));
		std::future<int> result2(std::async(std::launch::deferred, func2));
		int r1 = result1.get();
		int r2 = result2.get();
		cout << endl;
		cout << "result1=" << static_cast<char>(r1) << endl;
		cout << "result2=" << static_cast<char>(r2) << endl;
		cout << endl;
	}
	// exception
	{
		cout << "TEST exception handling" << endl;
		std::future<int> result(std::async(std::launch::deferred, func3));
		try 
		{
			int r = result.get();
			cout << "result=" << r << endl;
		}
		catch (int e)
		{
			cout << "catch exception=" << e << endl;
		}
		cout << endl;
	}
	cout << endl;
}