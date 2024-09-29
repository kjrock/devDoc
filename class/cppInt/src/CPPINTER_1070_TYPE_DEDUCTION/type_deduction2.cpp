template<typename T>
void foo(T n) {}

void goo(auto n) {} // C++20

int main()
{
	const int c = 10;

	auto n = c;

	foo(c);
}