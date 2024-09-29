int main()
{
	int n = 0;
	int* p = &n;

	decltype(p)   d1;	// 규칙 1. int* d1
	decltype(*p)  d2;	// 규칙 2. int& d2 
						// 초기값 문제로 error. 

	decltype(n)   d3;	// 규칙 1. int d3
	decltype((n)) d4;	// 규칙 2. int& d4
						// 초기값 문제로 error.

	decltype(n+1) d5;	// 규칙 2. int d5
	decltype(n=1) d6;	// 규칙 2. int& d6 - error
	
	decltype(++n) d7;	// 규칙 2. int& d7
	decltype(n++) d8;	// 규칙 2. int  d8 - error
}