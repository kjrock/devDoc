#include <type_traits>
#include "object.h"

template<typename T>
constexpr std::remove_reference_t<T>&& move( T&& obj ) noexcept
{
	return static_cast<std::remove_reference_t<T>&&>(obj);
}

int main()
{
	Object o1, o2;

	Object o3 = o1;					// copy
	Object o4 = move( o2 ); 		// move
	Object o5 = move( Object{} ); 	// move
		
}