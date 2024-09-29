#include "cmc.h"

template<typename T> void f2(T& arg) 
{
	log_function_name();
}

int main()
{
	int  n = 0;
	int& r = n;
	const int c = 0;
	const int& rc = c;

	f2(n);	// T=int	arg=int&
	f2(r);	// T=int	arg=int&
	f2(c);	// T=const int	arg=const int&
	f2(rc);	// T=const int	arg=const int&
}
