int x = 0;

int  f1() { return x;} // "값 0" 반환
int& f2() { return x;} // "x의 별명" 반환
void f3() {}

int main()
{
	int n = 1;

	(n = 2) = 1;	// ok
	(n + 2) = 1;	// error

	int* p1 = &(n = 2); // ok
	int* p2 = &(n + 2); // error

	f1() = 1; // 0 = 1. error
	f2() = 1; // x = 1. ok
	f3() = 1; // error

	3 = 1;
}