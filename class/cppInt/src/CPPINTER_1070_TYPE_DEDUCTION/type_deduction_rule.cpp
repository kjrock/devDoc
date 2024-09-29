#include <print>

template<typename T> void f1(T   arg) { }
template<typename T> void f2(T&  arg) { }
template<typename T> void f3(T&& arg) { }

int main()
{
	const int c = 0;
	
	f1(c);
	f2(c);
	f3(c);

	auto   a1 = c;
	auto&  a2 = c;
	auto&& a3 = c;
}
