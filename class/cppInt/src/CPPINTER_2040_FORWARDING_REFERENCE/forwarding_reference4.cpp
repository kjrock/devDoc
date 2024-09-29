#include "cmc.h"

template<typename T> 
void f3(T& arg) 
{		
	log_function_name();	
}
template<typename T>
void f4(T&& arg) 
{
	log_function_name();
}
int main()
{
	int n = 1;

	f3(n);  // T = int
//	f3(1);  // T = int. error

	f4(n);  // T = int&
	f4(1);  // T = int
}