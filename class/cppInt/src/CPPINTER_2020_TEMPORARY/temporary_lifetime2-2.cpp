#include "cmc.h"

template<typename T>
const T& Max(const T& a, const T& b)
{
	return (a < b) ? b : a;
}

int main()
{
//	String s1{"AAA"};
//	String s2{"BBB"};

//	String s3 = Max(s1, s2);

//	const String& s3 = Max(s1, s2); // ok 

	const String& s4 = Max(String{"AAA"}, 
						   String{"BBB"}); // bug
	std::println("-----------");
}

