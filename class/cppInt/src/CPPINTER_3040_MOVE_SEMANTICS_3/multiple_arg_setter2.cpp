#include <type_traits>
#include <concepts>
#include "String.h"

struct Object
{
	String name;
	String address;

	template<typename T1, typename T2>
	void set1(T1&& n, T2&& a)
	{ 
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}
	

	// until C++17. using std::enable_if_t
	template<typename T1, typename T2>
	std::enable_if_t< std::is_convertible_v<std::decay_t<T1>, String> &&
					  std::is_convertible_v<std::decay_t<T2>, String> >
	set2(T1&& n, T2&& a)
	{ 
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// since C++20. using concept
	template<std::convertible_to<String> T1,
			 std::convertible_to<String> T2>
	void set3(T1&& n, T2&& a)
	{ 
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}
};
int main()
{	
}