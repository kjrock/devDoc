#include <vector>
#include <array>
#include <string>
#include "cmc.h"

int main()
{
	std::vector<std::string>    v1{"A", "B", "C"};
	std::array<std::string, 3>  a1{"A", "B", "C"};

	auto v2 = std::move(v1);
	auto a2 = std::move(a1);

	show(v1); // [ ]
	show(v2); // [ "A", "B", "C" ]
	show(a1); // [ "", "", "" ]
	show(a2); // [ "A", "B", "C" ]
}