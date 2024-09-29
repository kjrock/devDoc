#include <print>
#include <source_location>
#include "cmc.h"
/*
void log_function_name( std::source_location loc 
						= std::source_location::current())
{
	std::println("{}", loc.function_name() );
}
*/

template<typename T> void foo(T arg)
{
	log_function_name();	
//	log_function_name(std::source_location::current());	
}

int main()
{
	const int c = 10;
	foo(c);
}
