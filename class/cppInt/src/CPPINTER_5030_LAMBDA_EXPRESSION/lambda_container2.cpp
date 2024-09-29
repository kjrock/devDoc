#include <functional>

int main()
{
	auto f1 = [](int a, int b) { return a + b;};
	f1      = [](int a, int b) { return a - b;}; // error

	int(*f2)(int, int) = 
			  [](int a, int b) { return a + b;};			  
	f2 = 	  [](int a, int b) { return a - b;}; // ok

	std::function<int(int, int)> f3 = 
			  [](int a, int b) { return a + b;};
	f3 = 	  [](int a, int b) { return a - b;}; // ok
}