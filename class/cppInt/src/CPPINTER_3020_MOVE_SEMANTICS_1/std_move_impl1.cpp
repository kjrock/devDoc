#include "object.h"

template<typename T>
T&& move( T& obj )
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1, o2;

	Object o3 = o1;			// copy
	Object o4 = move( o2 ); // move
	Object o5 = move( Object{} ); // error
		
}