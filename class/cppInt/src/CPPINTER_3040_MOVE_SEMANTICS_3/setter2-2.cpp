#include <vector>
#include "String.h"

int main()
{
	std::vector<String> v;
	v.reserve(10);

	String s1 = "s1";
	String s2 = "s2";

	v.push_back(s1);
	v.push_back(std::move(s2));
}