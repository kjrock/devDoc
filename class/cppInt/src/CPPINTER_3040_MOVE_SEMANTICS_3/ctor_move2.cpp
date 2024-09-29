#include "String.h"

struct Object
{
	String name;
	String address;

	template<typename T1, typename T2>
	Object(T1&& n, T2&& a)
		: name{ std::forward<T1>(n)},	
		  address{ std::forward<T2>(a)}
	{		
	}
};

int main()
{	
	String s1 = "s1";
	String s2 = "s2";

	Object obj{s1, std::move(s2)};
}