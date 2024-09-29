#include "cmc.h"

struct Object 
{
	String name{"name"};

	~Object() { std::println("~Object()");}

	String value_return() const { return name;}

	const String& reference_return() const { return name;}
};

int main()
{
//	const Object& o = Object{};		 // O
//	const String& s = Object{}.name; // O
//	const String& s = Object{}.reference_return(); // X
	const String& s = Object{}.value_return();	   // 

	std::println("---------------------");
}