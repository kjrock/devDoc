#include "cmc.h"

template<typename T>
void f1(T&& arg) 
{
	log_function_name();
}

void f2(auto&& arg) 
{	
	log_function_name();
} 

int main()
{
	int n = 1;

	auto&& a1 = n; // int&  a1 = n
	auto&& a2 = 1; // int&& a2 = 1

	f1(n);
	f1(1);
	f2(n);
	f2(1);
}
