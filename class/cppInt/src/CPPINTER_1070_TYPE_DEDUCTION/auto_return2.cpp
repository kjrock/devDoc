template<typename T1, typename T2>
auto add(T1 a, T2 b) // -> decltype(a + b)
{
//	if ( a == 0) return b;
	if ( b == 0) return a;

	return a + b;
}

int main()
{
	auto ret = add(1, 3.4);
}