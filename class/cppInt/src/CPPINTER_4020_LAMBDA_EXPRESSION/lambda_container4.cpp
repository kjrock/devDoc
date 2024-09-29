#include <functional>
#include <vector>
#include <print>

int add(int a, int b) { return a + b;}

int main()
{
	std::vector<std::function<int(int, int)>> v;

	v.push_back( [](int a, int b) { return a + b; } );
	v.push_back( std::plus<int>{} );
	v.push_back( add );

	std::println("{}", v[0](1,2));
	std::println("{}", v[1](1,2));
	std::println("{}", v[2](1,2));
}