void f1(int n) 			{}
void f2(const char* s) 	{}

int main()
{
	f1(3);
	f2("hello");

//	auto p1 = &3;		// error
	auto p2 = &"hello";	// ok

	auto c = "hello"[0];// ok

	"hello"[0] = 'x';	// error
						// "hello" : const char[6]

	3 = 5;
}

