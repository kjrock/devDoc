#include <print>

template<typename T> 
void foo(T arg)
{
//	std::println("{}", __func__);			// C++표준
//	std::println("{}", __FUNCSIG__);		// for cl
//	std::println("{}", __PRETTY_FUNCTION__);// for g++

	*arg = 3;
}

int main()
{	
	foo<const int&>(0);
}
