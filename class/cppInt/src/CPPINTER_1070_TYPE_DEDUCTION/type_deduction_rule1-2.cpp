#include "cmc.h"

template<typename T> void f1(T arg) 
{ 
	log_function_name();
}
int main()
{
	const char* s1 = "hello";
	const char* const s2 = "hello";

	f1(s1);	// T = const char*
	f1(s2); // T = const char* 
}
