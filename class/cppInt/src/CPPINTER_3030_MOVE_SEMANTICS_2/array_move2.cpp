#include <string>
#include <print>

template<typename ARRAY>
void print(const ARRAY& arr)
{	
	std::size_t sz = std::size(arr.x);

	std::print("[ {}", arr.x[0]);

	for(std::size_t i = 1; i < sz; i++)
		std::print(", {}", arr.x[i]);
	std::println(" ]");
}

template<typename T, std::size_t N>
struct ARRAY
{
	T x[N];
};

int main()
{
	ARRAY<int, 3> a1 = {1, 2, 3};
	ARRAY<int, 3> a2 = std::move(a1);

	ARRAY<std::string, 3> a3 = {"A", "B", "C"};
	ARRAY<std::string, 3> a4 = std::move(a3);

	print(a1);
	print(a2);
	print(a3);
	print(a4);
}