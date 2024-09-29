#include "String.h"

struct Object
{
	String name;

//	void set(const String& n) { name = n; }	
	void set(const String& n) { name = std::move(n); }	
};

int main()
{	
	Object obj;

	String s1 = "s1";
	String s2 = "s2";	

	obj.set(s1);
	obj.set(std::move(s2));

	std::println("{}", s1.c_str());	// "s1"
	std::println("{}", s2.c_str()); // ""   의도!	
									// "s2" 결과.	
									
}