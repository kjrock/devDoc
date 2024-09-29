template<typename T> void f1(      T&  arg) {}
template<typename T> void f2(const T&  arg) {}
template<typename T> void f3(      T&& arg) {}
template<typename T> void f4(const T&& arg) {}

int main()
{
	int n = 1;

	f1(n);	// ok
	f1(1);	// error

	f2(n);	// ok
	f2(1);  // ok

	f3(n);	// ok
	f3(1);	// ok 

	f4(n);	// error
	f4(1);	// ok
}