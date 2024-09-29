#include "String.h"

struct Object
{
	String name;
	Object(const String& n) : name(n) {}

	// # 사용자가 복사 생성자를 제공한 경우.
	Object(const Object& other) : name{other.name}
	{
		std::println("Object Copy");
	}

	Object(Object&&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;		
};
int main()
{	
	Object o1{"o1"};
	Object o2{"o2"};
	std::println("-------------");

	Object o3 = o1;				
	Object o4 = std::move(o2);	
}