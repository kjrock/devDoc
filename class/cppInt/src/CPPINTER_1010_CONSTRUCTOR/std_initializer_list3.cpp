#include <initializer_list>

void f1( int* p ) {}
void f2( std::initializer_list<int> s) {}

int main()
{
	int x[5] = {1, 2, 3, 4, 5};
	f1( x );
//	f1( {1,2,3} );	// error

	std::initializer_list<int> s = {1, 2, 3, 4, 5};
	f2( s );		// ok
	f2( {1,2,3} );	// ok
//	f2( x );		// error
}
