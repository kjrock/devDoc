#include "String.h"

int main()
{	
	String s1{"to be or not to be"};

	String s2 = s1;
	String s3 = std::move(s1);

	s3 = s2;
	s3 = std::move(s2);	
}