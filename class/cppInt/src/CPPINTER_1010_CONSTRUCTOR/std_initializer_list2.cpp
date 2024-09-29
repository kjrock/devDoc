#include <initializer_list>

void foo( std::initializer_list<int> s) {}

int main()
{
	std::initializer_list<int> s = {1, 2, 3, 4, 5};

	foo( s );

	foo( {1, 2, 3} );
	foo( {1, 2, 3, 4, 5} );
}
