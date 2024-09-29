#include <print>
#include <source_location>

template<typename T> 
void foo(T arg)
{
	std::source_location loc = 
			std::source_location::current();

	std::println("{}", loc.function_name());
	std::println("{}", loc.file_name());
	std::println("{}", loc.line());			
}

int main()
{
	const int c = 10;
	foo(c);
}
