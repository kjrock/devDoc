<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# literal 과 타입
- 모든 리터럴은 타입이 있다.

||||
|--|--|--|
|0|정수형 리터럴|int|
|0.0|실수형 리터럴|double|
|false|bool형 리터럴|bool|
|nullptr|포인터형 리터럴|std::nullptr_t|

# std::nullptr_t
- nullptr의 타입
- 모든 종류의 포인터로 암시적 형변환 된다.

```c++
#include <iostream>

void foo(int)    { std::cout << "int"    << std::endl;}
void foo(double) { std::cout << "double" << std::endl;}
void foo(bool)   { std::cout << "bool"  << std::endl;}
void foo(char*)  { std::cout << "char*" << std::endl;}

int main()
{
	foo(0);   		// foo(int)
	foo(0.0); 		// foo(double)
	foo(false); 	// foo(bool)
	foo(nullptr);	// foo(char*)

	std::nullptr_t null = nullptr;

	int*  p1 = null;
	char* p2 = null;
}
```

# 결론
- 포인터 변수를 초기화할때는 0을 사용하지 말고, <r>nullptr을 사용하자.</r>
- nullptr 의 타입은 <r>std::nullptr_t</r>이다.

```c++
#include <iostream>

template<class F, class T>
void call(F f, T arg)  // int arg = 0
{					   // std::nullptr_t arg = nullptr
	f(arg);
}

void foo(int  a) {}
void goo(int* p) {}

int main()
{
	foo(10); // ok
	goo(0);	 // ok

	call(foo, 10); 	// foo(10). ok
//	call(goo, 0);  	// goo(0)==> goo(arg)
					// error
	call(goo, nullptr); // ok
}
```

# nullptr과 변환
- 모든 종류의 포인터로 초기화시에 사용될수 있다.
- bool 변수의 <r>직접 초기화(direct initialization></r>에 사용될수 있다.

# nullptr과 조건문
- nullptr은 조건문에 사용될 수 있다.
  
```c++
int main()
{
	int*    p1 = nullptr; // ok
	double* p2 = nullptr; // ok

	int n1 = nullptr;	// error
	int n2{nullptr};	// error

	bool b1 = nullptr;	// error
	bool b2{nullptr};	// ok

	if ( nullptr ) {}	// ok
}
```