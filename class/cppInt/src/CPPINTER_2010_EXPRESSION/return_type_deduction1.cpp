#include <print>

auto next1()			// int next1()		
{ 
	static int n = 0;
	return ++n; 
}

decltype(auto) next2() 	// int& next2()	
{ 
	static int n = 0;
	return ++n; 
}

int main()
{
	std::println("{}, {}", next1(), next2()); // 1, 1
	std::println("{}, {}", next1(), next2()); // 2, 2

//	next1() = 0;	// error
	next2() = 0;	// ok

	std::println("{}, {}", next1(), next2());// 3, 1	
}
