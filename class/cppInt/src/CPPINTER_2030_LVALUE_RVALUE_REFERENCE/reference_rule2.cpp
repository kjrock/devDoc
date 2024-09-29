struct Point 
{ 
	int x;
	int y; 
};

int main()
{
	Point pt{1, 2};

	Point& r1 = pt;					// ok
	Point& r2 = Point{1, 2};		// error

	const Point& r3 = pt;			// ok
	const Point& r4 = Point{1, 2};	// ok

	Point&& r5 = pt;				// error
	Point&& r6 = Point{1, 2};		// ok
}