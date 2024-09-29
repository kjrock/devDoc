#include "String.h"

struct Object
{
	String name;

};

int main()
{	
	Object o1{"o1"};
	Object o2{"o2"};

	Object o3 = o1;				// 
	Object o4 = std::move(o2);	// 

	std::println("{}", o1.name.c_str()); // "o1"
	std::println("{}", o2.name.c_str()); // ""
}