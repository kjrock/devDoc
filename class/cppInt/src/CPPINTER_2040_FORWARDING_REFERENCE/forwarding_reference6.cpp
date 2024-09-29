#include "cmc.h"

template<typename T>
void foo(T&& n) 
{
	log_function_name();
}

int main()
{	
	int n = 1;

	foo(n); 
	foo(1);	
}