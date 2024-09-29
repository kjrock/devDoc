#include <type_traits>
#include "object.h"

template<typename T>
void foo(T&& obj)
{
	Object o1 = static_cast<Object&&>(obj);

	Object o2 = static_cast<T&&>(obj);

	Object o3 = static_cast<
					std::remove_reference_t<T>&&>(obj);
}

int main()
{
	Object obj;
	foo( obj );		// foo(lvalue)
	foo( Object{} );// foo(rvalue)
}