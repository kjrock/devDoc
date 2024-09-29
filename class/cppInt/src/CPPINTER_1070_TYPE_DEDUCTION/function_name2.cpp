#include <print>

template<typename T> 
void foo(T arg)
{
	std::println("{}", typeid(T).name() );
}

int main()
{	
	foo<const int&>(0);
}
