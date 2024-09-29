#include <utility>
#include <print>

int main()
{
	int n1 = 3;
	int n2 = std::move(n1);
				// static_cast<int&&>(n1);

	std::println("{}, {}", n1, n2); // 3, 3


	int* p1 = new int;
	int* p2 = std::move(p1);
				// static_cast<int*&&>(p1);
	
	delete p1;
}
