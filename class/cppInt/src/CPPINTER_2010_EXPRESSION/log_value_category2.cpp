#include <print>
#include <type_traits>
#include "cmc.h"

/*
#define log_value_category( ... )										\
	if ( std::is_lvalue_reference_v< decltype((__VA_ARGS__)) > )		\
		std::println("lvalue");											\
	else if ( std::is_rvalue_reference_v< decltype((__VA_ARGS__)) > )	\
		std::println("rvalue(xvalue)");									\
	else 																\
		std::println("rvalue(prvalue)");
*/
int main()
{
	int n = 1;
	
	log_value_category(n);		// lvalue
	log_value_category(n+1);	// rvalue(prvalue)
	log_value_category(++n);	// lvalue
	log_value_category(n++);	// rvalue(prvalue)

	log_value_category(3);		// rvalue(prvalue)
	log_value_category(3.4);	// rvalue(prvalue)

	log_value_category("hello");// lvalue
}
