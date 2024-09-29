#include "cmc.h"

const String& foo(const String& arg ) {	return arg;}

int main()
{
//	const String& s = String{"ABCD"};

	const String& s = foo( String{"ABCD"} );

	std::println("-------------------");
}
