#include "String.h"

int main()
{
	String s1{"s1"};
	String s2 = s1;				// copy
	String s3 = std::move(s1);	// move
}