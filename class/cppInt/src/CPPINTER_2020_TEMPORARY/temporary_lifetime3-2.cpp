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
//	for ( auto e : Object{}.name )			// O

//	for ( auto e : Object{}.reference_return() )	// X	

//	for ( auto e : Object{}.value_return() )		// O

	for ( const Object& obj = Object{}; auto e : obj.reference_return() )  // O
	{
		std::println("{}", e);
	}
	std::println("----------------");
}