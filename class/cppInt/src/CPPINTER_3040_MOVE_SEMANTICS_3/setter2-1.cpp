#include "String.h"

struct Object
{
	String name;

	// #1. 2개의 setter method.
	void set(const String& n) { name = n; }	
	void set(String&& n)      { name = std::move(n); }		
};
int main()
{	
	Object obj;

	String s1 = "s1";
	String s2 = "s2";	

	obj.set(s1);
	obj.set(std::move(s2));

	std::println("{}", s1.c_str());	// "s1"
	std::println("{}", s2.c_str()); // ""   
}