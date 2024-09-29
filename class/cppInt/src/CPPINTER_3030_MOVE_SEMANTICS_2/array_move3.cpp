#include <vector>
#include <array>
#include "cmc.h"

int main()
{
	std::vector<int>    v1{1, 2, 3};
	std::array<int, 3>  a1{1, 2, 3};

	auto v2 = std::move(v1);
	auto a2 = std::move(a1);

	show(v1); // [ ]
	show(v2); // [ 1, 2, 3 ] 
	show(a1); // [ 1, 2, 3 ]
	show(a2); // [ 1, 2, 3 ]
}