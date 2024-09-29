#include <print>
#include <initializer_list>

int main()
{
	std::initializer_list<int> s = {1, 2, 3, 4, 5};

//	int* first = s.begin();	// error

	const int* first = s.begin();	
	const int* lst   = s.end();

	for( auto e : s)
	{
		std::println("{}", e);
	}
}
