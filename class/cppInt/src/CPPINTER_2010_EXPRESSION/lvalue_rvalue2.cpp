int main()
{
	int n = 1;

	n = 1; // ok
	3 = 1; // error

	n + 2       = 1; // error
	(n + 2) * 3 = 1; // error

	++n = 1; // ok
	n++ = 1; // error
}