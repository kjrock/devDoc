#include <string>

template<typename T>
void copy_swap(T& lhs, T& rhs)
{
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template<typename T>
void move_swap(T& lhs, T& rhs)
{
	T tmp = std::move(lhs);
	lhs = std::move(rhs);
	rhs = std::move(tmp);
}

int main()
{
	std::string s1 = "Practice make perfect";
	std::string s2 = "To be or not to be";

	copy_swap(s1, s2); // bad
	move_swap(s1, s2); // bad
}