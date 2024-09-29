#include "String.h"

struct Object
{
	String name;
	Object(const String& n) : name(n) {}

	// # 사용자가 이동 생성자를 제공한 경우.
	Object(Object&& other) : name{std::move(other.name)}
	{
		std::println("Object move");
	}
};
int main()
{	
	Object o1{"o1"};
	Object o2{"o2"};
	std::println("-------------");

	Object o3 = o1;			// error	
	Object o4 = std::move(o2);	
}