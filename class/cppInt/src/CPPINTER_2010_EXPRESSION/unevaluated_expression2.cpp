#include <print>

int add(int a, int b);

int main()
{
	std::println("{}", sizeof(add(1,2)));
	std::println("{}", noexcept(add(1,2)));
	std::println("{}", typeid(add(1,2)).name());
	
	using T = decltype( add(1, 2) );
}

