#include "String.h"

struct Object
{
	String name;
	String address;

	void set(const String& n, const String& a)
	{ 
		name = n;
		address = a; 
	}
	void set(String&& n, String&& a)
	{ 
		name = std::move(n);
		address = std::move(a); 
	}	
	void set(const String& n, String&& a)
	{ 
		name = n;
		address = std::move(a); 
	}	
	void set(String&& n, const String& a)
	{ 
		name = std::move(n);
		address = a; 
	}		
};

int main()
{	
	Object obj;

	String s1 = "s1";
	String s2 = "s2";

	obj.set(s1,            s2);
//	obj.set(std::move(s1), std::move(s2));
//	obj.set(s2, 		   std::move(s2));
//	obj.set(std::move(s1), s2);
}