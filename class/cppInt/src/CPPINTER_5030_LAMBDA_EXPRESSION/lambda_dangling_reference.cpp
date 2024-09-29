#include <functional>
#include <print>

int main()
{
	std::function<int(int)> f;

	{
		int n = 0;

		f = [&n](int a) { return a + n;};

	}	// <= n 파괴

	std::println("{}", f(10) ); // 10 + n  ?
}