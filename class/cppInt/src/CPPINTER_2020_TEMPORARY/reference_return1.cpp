struct Point { int x = 0, y = 0;};

int x = 3;
int  f1() { return x;}	// '3' 반환
int& f2() { return x;}	// 'x' 반환

Point pt{1, 1};
Point  f3() { return pt;}
Point& f4() { return pt;}

int main()
{
	f1() = 0;	// error. "3 = 0"
	f2() = 0;	// ok     "x = 0"

	f3().x = 0; // error. "temporary.x = 0"
	f4().x = 0;	// ok     "pt.x = 0"
}
