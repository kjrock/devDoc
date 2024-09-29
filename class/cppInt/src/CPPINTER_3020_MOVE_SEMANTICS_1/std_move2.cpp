#include <print>
#include <string>

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";
	std::string s3 = "to be or not to be";

	auto s4 = s1;			
	auto s5 = std::move(s2);
	auto s6 = static_cast<std::string&&>(s3);

	std::println("{}", s1); // 
	std::println("{}", s2);
	std::println("{}", s3);
}