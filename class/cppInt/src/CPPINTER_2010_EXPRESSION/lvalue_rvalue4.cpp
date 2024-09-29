int main()
{
	const int c = 1;

	c = 1; 	// error.
			// "c" 
			// 1. lvalue expression => ok
			// 2. rvalue expression

	int n = 1;
	n + 1 = 3;
}