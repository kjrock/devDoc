int main()
{
	int n = 0;

	auto a = n;		// int a = n;

	decltype(n) d;	// int n;


	auto a1 = n;	 // "n"    id-expression
	auto a2 = n + 2; // "n+2"  id-expression X
}