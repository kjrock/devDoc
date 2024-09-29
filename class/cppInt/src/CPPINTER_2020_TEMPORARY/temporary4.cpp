struct Point
{
	int x, y;
	Point(int a, int b) : x{a}, y{b} { }	
};

void reset(Point& pt) { pt.x = 0; pt.y = 0;}

void draw_line(const Point& from, const Point& to) {}

int main()
{
	// #1. 객체를 생성해서 함수 인자로 사용
	Point from{0, 0};
	Point to{30, 30};
	draw_line(from, to);

	// #2. 
	draw_line(Point {0, 0}, Point {30, 30} );


	reset(from);	// ok

	reset( Point {30, 30} ); // error. 
}