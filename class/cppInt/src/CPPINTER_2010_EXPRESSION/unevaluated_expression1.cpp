#include <print>

int add(int a, int b);
/*
int add(int a, int b) 
{ 
	std::println("add");
	return a + b; 
}
*/
int main()
{
	int n = 0;
	std::println("{}", sizeof(int)  );	// 4
	std::println("{}", sizeof n     );	// 4
	std::println("{}", sizeof &add  );	// 4, 8
//	std::println("{}", sizeof add   );	// error

	std::println("{}", sizeof add(1, 2)  );	// 4
}

