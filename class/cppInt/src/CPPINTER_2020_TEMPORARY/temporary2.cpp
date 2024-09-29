struct Point
{
	int x, y;
	Point(int a, int b) : x{a}, y{b} { }	
};

int main()
{
	Point{1, 1}.x = 0;	     // error.

	Point* p = &Point{1, 1}; // error.

	Point& r1 = Point{1, 1}; // error.

	const Point& r2 = Point{1, 1};// ok

	Point&& r3 = Point{1, 1}; // ok
}