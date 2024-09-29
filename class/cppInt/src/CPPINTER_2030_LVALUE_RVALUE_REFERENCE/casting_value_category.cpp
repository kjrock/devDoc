#include <print>

struct Point { int x, y; };

void foo(Point&  pt) { std::println("1. Point&");  }
void foo(Point&& pt) { std::println("2. Point&&"); }

int main()
{	
	Point pt{1, 2};

	foo( pt );			// 1
	foo( Point{1, 2} );	// 2
	
	foo( static_cast<Point&&>(pt) );	// 2
	foo( static_cast<Point>(pt) );		// 2

//	foo( static_cast<Point&>(pt) );		// 1
//	foo( static_cast<Point&>(Point{1,2}) ); // error
}




