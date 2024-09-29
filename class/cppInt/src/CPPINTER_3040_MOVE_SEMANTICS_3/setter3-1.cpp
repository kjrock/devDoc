#include "String.h"

struct Object
{
	String name;

	// #1. 2개의 setter method.
//	void set(const String& n) { name = n; }	
//	void set(String&& n)      { name = std::move(n); }

	// #2. 
	template<typename T>
	void set(T&& n)
	{
//		name = n;
//		name = std::move(n);
		name = std::forward<T>(n);
	}
};

int main()
{	
	Object obj;

	String s1 = "s1";
	String s2 = "s2";	

	obj.set(s1);
	obj.set(std::move(s2));
}