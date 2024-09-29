#include <vector>
#include <print>

int main()
{
	std::vector v1(10, 2);
	std::vector v2{10, 2};

	std::println("{}", v1.size());	// 10
	std::println("{}", v2.size());	// 2

	std::vector v3 = 10;	// error
	std::vector v4 = {10}; 	// ok
}