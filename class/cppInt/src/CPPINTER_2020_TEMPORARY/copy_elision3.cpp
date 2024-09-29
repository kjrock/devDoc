#include <iostream>

struct Point
{
	Point(int a, int b) { std::cout << "Point(int, int)\n";}		
	~Point()            { std::cout << "~Point()\n";}
	Point(const Point&) { std::cout << "Point(const Point&)\n";}
};

Point foo() 
{ 
	Point pt{1, 2}; // 전역변수가 아닌 지역변수
	return pt; 	
}

int main()
{
	std::cout << "--------\n";

	Point ret = foo();

	std::cout << "--------\n";
}






