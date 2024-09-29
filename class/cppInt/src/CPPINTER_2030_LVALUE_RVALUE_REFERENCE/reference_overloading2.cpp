#include <print>

struct Point { int x, y; };

void foo(Point&  pt) { std::println("1. Point&");  }
void foo(Point&& pt) { std::println("2. Point&&"); }

int main()
{	
	Point pt{1, 2};

	Point&  r1 = pt;
	foo(r1);		// 1

	Point&& r2 = Point{1, 2};
	foo(r2);		// 1

	foo( static_cast<Point&&>(r2) ); // 2
}




