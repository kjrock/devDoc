#include <print>

struct Point { int x, y; };

void foo(Point&  pt) {std::println("1. Point&"); }
void foo(Point&& pt) {std::println("2. Point&&");}
void foo(const Point&  pt) {std::println("3. const Point&");}

int main()
{
	Point pt{1, 2};

	foo( pt );			// 1

	foo( Point{1,2} );	// 2

	const Point cp{1,2};
	foo(cp);			// 3
}


