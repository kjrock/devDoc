int x = 0;
int& f1() { return x;}

//auto foo()			// int foo()
decltype(auto) foo()	// int& foo()
{
	return f1();
}

int main()
{
	int& ret = foo();
}