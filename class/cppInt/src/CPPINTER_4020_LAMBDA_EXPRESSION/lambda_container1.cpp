#include <functional>

int main()
{
	auto f1 = [](int a, int b) { return a + b;};

	int(*f2)(int, int) = 
			  [](int a, int b) { return a + b;};

	std::function<int(int, int)> f3 = 
			  [](int a, int b) { return a + b;};

	f1(1, 2);
	f2(1, 2);
	f3(1, 2);
}