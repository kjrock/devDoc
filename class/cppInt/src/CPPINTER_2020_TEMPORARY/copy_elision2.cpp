#include <iostream>

struct Point
{
	Point(int a, int b) { std::cout << "Point(int, int)\n";}		
	~Point()            { std::cout << "~Point()\n";}
	Point(const Point&) { std::cout << "Point(const Point&)\n";}
};

Point pt{1, 2};

Point foo() { return pt; }

int main()
{
	std::cout << "--------\n";

	Point ret = foo();

	std::cout << "--------\n";
}






