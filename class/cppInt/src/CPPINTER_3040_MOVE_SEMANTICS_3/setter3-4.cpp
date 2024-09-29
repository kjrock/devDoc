#include <string>
#include <concepts>
#include <type_traits>

struct Object
{
	std::string name;

	// # since C++20 
	template< std::convertible_to<std::string> T>
	void set1(T&& n) 
	{		
		name = std::forward<T>(n);
	}	

	// # until C++17
	template<typename T>
	std::enable_if_t< 
		std::is_convertible_v<std::decay_t<T>, std::string>>
	set2(T&& n)
	{
		name = std::forward<T>(n);
	}	

};

int main()
{	
	Object obj;

	obj.set1("AA");	// ok
	obj.set2("AA"); // ok
//	obj.set1(65);	// error
//	obj.set2(65);	// error
}