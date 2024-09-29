#include <print>

int& foo(int& r) { return r;}

int main()
{
	int n = 0;

	decltype(foo(n)) ret1 = foo(n); // int& ret1 = 			

	auto             ret2 = foo(n); // int  ret2 = 
			 
	decltype(auto)   ret3 = foo(n);	// int& ret3 = 
			 
	n = 3;

	std::println("{}, {}, {}", ret1, ret2, ret3);
							// 3,    0,    3

}