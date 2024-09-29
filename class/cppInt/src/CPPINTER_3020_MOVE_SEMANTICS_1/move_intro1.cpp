#include <print>
#include <string>

int main()
{
	std::string s1 = "Practice make perfect";
	std::string s2 = s1;

	std::string s3 = "Practice make perfect";
	std::string s4 = std::move(s3);

	std::println("{}", s1); // "Practice make perfect"
	std::println("{}", s2); // "Practice make perfect"
	std::println("{}", s3); // ""
	std::println("{}", s4); // "Practice make perfect"
}
