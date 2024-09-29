template<typename T>
void f3(T& arg)
{
}

int main()
{
	int n = 1;

	// #1. 타입 인자를 명시적으로 전달하는 경우
	f3<int>( n );		// f3(int& arg)
	f3<int&>( n );		// f3(int& arg)
	f3<int&&>( n );		// f3(int& arg)

	// #2. 타입 인자를 명시적으로 전달하지 않은 경우
	f3(n); // ok
	f3(1); // error
}