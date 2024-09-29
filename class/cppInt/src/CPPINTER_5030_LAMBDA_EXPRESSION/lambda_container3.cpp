#include <functional>

int main()
{
	int v = 0;
	int(*f1)(int a, int b) = [v](int a, int b) { return a + b + v;};	// error		  
	int(*f2)(int a, int b) = std::plus<int>{};							// error  

	std::function<int(int, int)> f3 = [v](int a, int b) { return a + b + v;}; 	// ok
	std::function<int(int, int)> f4 = std::plus<int>{};							// ok
}