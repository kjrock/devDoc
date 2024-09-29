struct Point 
{
	int x, y;
};

// #1. call by value 
// void foo(Point pt) {}


// #2. call by const lvalue reference
// void foo(const Point& pt) {}



// #3. overloading
// void foo(Point&  pt) {}
// void foo(Point&& pt) {}


// #4. forwarding reference
template<typename T>
void foo(T&&  pt) {}

int main()
{
	Point pt = {1, 1};

	foo( pt );			// passing lvalue
	foo( Point{1, 1} ); // passing rvalue

//	const Point cp = {1,1};
//	foo( cp );


}
