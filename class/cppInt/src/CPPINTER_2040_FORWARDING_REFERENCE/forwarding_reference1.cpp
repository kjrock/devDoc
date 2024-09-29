void f1(int&  arg) {}
void f2(int&& arg) {}

template<typename T>
void f3(T& arg) {}

int main()
{
	int n = 1;

	f1(n); // ok
	f1(1); // error

	f2(n); // error
	f2(1); // ok
}