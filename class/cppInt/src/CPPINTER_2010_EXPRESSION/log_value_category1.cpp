#include <print>
#include <type_traits>

int main()
{
	int n = 1;

//	using expr_type = decltype( (n + 1) );
//	using expr_type = decltype( (n = 1) );
	using expr_type = decltype( ( n ) );

	if ( std::is_lvalue_reference_v< expr_type > )
		std::println("lvalue");
	else 
		std::println("rvalue");
}
