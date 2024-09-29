#include "String.h"

struct Object
{
	String name;

	Object(const String& n) : name{n} {}	
	Object(String&& n)      : name{std::move(n)} {}	
};

int main()
{	
	String s1 = "s1";
	String s2 = "s2";	

	Object obj1{s1};
	Object obj2{std::move(s2)};
}