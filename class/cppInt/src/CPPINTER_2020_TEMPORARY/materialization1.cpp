#include <iostream>

struct Point
{
	Point(int a, int b) { std::cout << "Point(int, int)\n";}		
	~Point()            { std::cout << "~Point()\n";}	
	Point(const Point&) { std::cout << "Point(const Point&)\n";}
};


int main()
{
	Point p1 = Point{1, 2};

	const Point& p2 = Point{1, 2};
}
