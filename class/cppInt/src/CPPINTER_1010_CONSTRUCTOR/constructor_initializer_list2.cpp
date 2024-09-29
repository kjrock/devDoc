#include <vector>

int main()
{
	std::vector<int> v1{1, 2, 3};
	std::vector<int> v2 = {1, 2, 3};

	// C++17 부터 template type 인자도 생략 가능.
	std::vector v3{1, 2, 3};
	std::vector v4 = {1, 2, 3};
}