<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 0
- 정수(int)형 literal
- <r>포인터 변수 초기화에 사용될 수 있다.</r> (포이터로 암시적 형 변환)
- 0이 아닌 <r>다른 정수형 literal</r>은 포인터로 암시적 변활될 수 없다.
- 0을 가진 정수형 변수도 포인터 변수로 암시적 변환될 수 없다.

# nullptr
- C++11에서 도입
- <r>null pointer</r>을 나타내는 literal, keyword
- 모든 종류의 포이터 변수를 초기화하는데 사용 가능
- 정수(실수) 초기화에 사용될수는 없다.

<r>[핵심] 포인터 변수를 초기화할때는 0을 사용하지 말고, nullptr을 사용하자.</r>

```c++
int main()
{
	int  n1 = 0;
	int* p1 = 0; 	// ok

	int* p2 = 10; 	// error
	int* p3 = n1; 	// error


	int* p4 = nullptr;    	// ok
	void(*p5)() = nullptr;	// ok

	int  n2 = nullptr; // error
}
```

[void* 암시적 형변환 안됨(C++)]
```c++
#include <iostream>

#define NULL (void*)0   // c 표준에서 이렇게 제공

void foo(int   n) { std::cout << "int"   << std::endl;}
void foo(void* p) { std::cout << "void*" << std::endl;}

void goo(char* p) { std::cout << "char*" << std::endl;}

int main()
{
	foo(0);  		// foo(int)
	foo((void*)0);	// foo(void*)
	foo(NULL);	// 

	goo(0);    // ok
	goo(NULL); // void* => char* 필요
			   // C 언어 : ok, C++ : error
}
```
# C vs C++ void* 

|||
|--|--|
|C|void* -> char*로의 암시적 <r>변환 허용</r>|
|C++|void* -> char*로의 암시적 <r>변환 허용 안함</r>|

# __cplusplus 매크로
- 모든 C++ 컴파일러가 제공하는 매크로
- 현재 컴파일러가 c/c++ 여부에 따라 다르게 동작하는 코드를 작성할때 사용

[C++ 컴파일러의 NULL]

```c++
#ifdef __cplusplus
//	#define NULL 0      // cl
	#define NULL 0L     // g++
#else
	#define NULL (void*)0
#endif
```

# NULL
- <r>포이터 0</r>의 의미로 사용하기 위해 만든 매크로
- 일반적으로 C언어와 C++언어에서 다르게 정의

|||
|--|--|
|C|(void*)0|
|C++|0 또는 0L|