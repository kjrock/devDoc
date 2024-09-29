void f1(int n) {}

template<typename T>
void f2(T n) {}

int main()
{	
	int n = 1;

	f1(n); 	// ok
	f1(1);	// ok

	f2(n); 	// ok
	f2(1);	// ok
	f2("A");// ok
}