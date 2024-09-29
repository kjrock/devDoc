int main()
{
	int  n = 0;
	int& r = n;
	const int c = 0;
	const int& rc = c;

	auto a1 = n;	// int a1
	auto a2 = r;	// int a2
	auto a3 = c;	// int a3
	auto a4 = rc;	// int a4

	const char* s1 = "hello";
	const char* const s2 = "hello";

	auto a5 = s1;	// const char* a5
	auto a6 = s1;	// const char* a6
}