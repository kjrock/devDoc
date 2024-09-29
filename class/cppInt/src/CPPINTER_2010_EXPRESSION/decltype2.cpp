struct Point { int x = 0, y = 0; };

int add(int a, int b);// { return a + b;}
void f1(int a) 	  {}
void f1(double a) {}

int main()
{
	int n = 0;
	Point pt;

	// id-expression  
	decltype(n)  d1;	// int  d1;
	decltype(pt) d2; 	// Point d2;

	// class member access expression
	decltype(pt.x) d3;	// int d3;

	// function call expression
	decltype( add(1, 2) ) d4; // int d4;

	// id-expression
	decltype(add) d5; // int d5(int , int )
	decltype(f1) d6;  // error
}