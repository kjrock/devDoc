struct Point { int x, y; };

void f1(      Point& pt)  { } 
void f2(const Point& pt)  { } 

void f3(      Point&& pt) { }
void f4(const Point&& pt) { }

int main()
{
	Point pt{1, 2};

	f1( pt );			// ok
	f1( Point{1, 2} );	// error

	f2( pt );			// ok
	f2( Point{1, 2} );	// ok

	f3( pt );			// error
	f3( Point{1, 2} );	// ok

	f4( pt );			// error
	f4( Point{1, 2} );	// ok
}