#include "cmc.h"

struct Reference
{
	const String& obj;
	
	Reference(const String& p) : obj(p) {}
};

int main()
{
	Reference ref( String{"ABCD"} );

	std::println("--------------");

}
