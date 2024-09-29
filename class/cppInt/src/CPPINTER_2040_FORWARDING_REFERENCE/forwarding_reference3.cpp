template<typename T>
void f4(T&& arg)
{
}
int main()
{
	int n = 1;

	// #1. 타입 인자를 명시적으로 전달하는 경우
	f4<int>( 1 );		// f4(int&&)
	f4<int&>( n );		// f4(int&)
	f4<int&&>( 1 );		// f4(int&&)

	// #2. 타입 인자를 명시적으로 전달하지 않은 경우
	f4(1); // T=int
	f4(n); // T=int&	
}