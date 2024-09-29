int main()
{
	int n = 1;

	n = 1; 	// ok.
	1 = n;	// error. 


	auto a = (n + 2) * 3; // int a = 9

	(n + 2) * 3 = 3;	
}
