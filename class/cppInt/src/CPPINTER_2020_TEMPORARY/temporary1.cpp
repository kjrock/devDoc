#include <print>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x{a}, y{b} 
	{ 
		std::println("Point(int, int)");
	}	
	~Point() { std::println("~Point()"); }
};

int main()
{
//	Point pt{1,2};
//	Point {1,2};	// unnamed object


	Point {1,2}, std::println("X");

	std::println("-----------------");
}
