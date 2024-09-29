#include <type_traits>
#include "object.h"

template<typename T>
void f1(T&& obj) { Object o = std::move(obj); }

template<typename T>
void f2(T&& obj) { Object o = std::forward<T>(obj); }

int main()
{
	Object obj;
	f1( obj );		// move
	f1( Object{} ); // move

	f2( obj );		// copy
	f2( Object{} ); // move
}