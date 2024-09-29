#include <string>
#include <print>
// #include "cmc.h"

struct String : public std::string
{
	// inherit constructor 
	using std::string::basic_string;

	~String()
	{
		std::println("~String() [\"{}\"]", data() );
	}
};

int main()
{
	String {"ABCD"};
	
	std::println("-------------------");
}