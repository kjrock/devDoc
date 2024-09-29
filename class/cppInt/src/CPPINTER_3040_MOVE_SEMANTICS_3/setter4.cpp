#include "String.h"

struct Object
{
	String name;
	
//	void set(String n) { name = n; } 
	void set(String n) { name = std::move(n); }	

	// #1
	void set1(const String& n) { name = n; }	
	void set1(String&& n)      { name = std::move(n); }	
};

int main()
{	
	Object obj;

	String s1 = "s1";
	String s2 = "s2";	

	obj.set(s1);			// COPY, MOVE		
	obj.set(std::move(s2));	// MOVE, MOVE

	obj.set1(s1);			// COPY
	obj.set1(std::move(s2));// MOVE	
}