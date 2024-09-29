#include "cmc.h"

template<typename T> void f1(T arg) 
{ 
	log_function_name();
}

int main()
{
	int  n = 0;
	int& r = n;
	const int c = 0;
	const int& rc = c;
	
	f1(n);	// T=int
	f1(r);	// T=int
	f1(c);	// T=int
	f1(rc);	// T=int
}
