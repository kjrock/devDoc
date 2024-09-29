#include "cmc.h"

template<typename T>
void foo(T arg) { log_function_name();}

template<typename T>
void goo(T& arg) { log_function_name(); }

void f1(int a) {}

int main()
{
	int arr[3] = {1,2,3};

	foo(arr);
	goo(arr);

	foo(f1);
	goo(f1);
}