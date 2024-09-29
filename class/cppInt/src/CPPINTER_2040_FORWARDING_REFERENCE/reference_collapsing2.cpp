void ex1()
{
	int n = 1;

	using LREF = int&;	// typedef int&  LREF;
	using RREF = int&&;	// typedef int&& RREF;

	LREF&  lrlr = n ; // int&  &  => int&	
	LREF&& lrrr = n ; // int&  && => int&
	RREF&  rrlr = n ; // int&& &  => int&
	RREF&& rrrr = 1 ; // int&& && => int&&
}








void ex2()
{
	int n = 1;

	int&  lr = n;
	int&& rr = 1;

	decltype(lr)&  lrlr = n ; // int&  &	
	decltype(lr)&& lrrr = n ; // int&  &&
	decltype(rr)&  rrlr = n ; // int&& &
	decltype(rr)&& rrrr = 1 ; // int&& &&
}








template<typename T>
void ex3(T&& arg)
{
}

int main()
{
	int n = 1;
	ex3<int>( 1 );		// int   && arg => int&&
	ex3<int&>( n );		// int&  && arg => int&
	ex3<int&&>( 1 );	// int&& && arg => int&&
}