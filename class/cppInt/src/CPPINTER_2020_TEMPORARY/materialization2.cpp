#include <iostream>

struct Point
{
	Point(int a, int b) { std::cout << "Point(int, int)\n";}		
	~Point()            { std::cout << "~Point()\n";}
	Point(const Point&) { std::cout << "Point(const Point&)\n";}
};

Point pt{1, 2};

Point foo() 
{ 
	std::cout << "foo\n";
	return pt; 
}

int main()
{
	std::cout << "--------\n";

//	Point ret = foo();	// temporary X
//	foo();				// temporary O

	Point{1, 2};// temporary O
	Point pt = Point{1,2};// temporary X

	std::cout << "--------\n";
}






