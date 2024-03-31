<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# reinterpret_cast
- 메모리의 재해석(reinterpret)
- 메모리의 해석 방식을 변경하는 캐스팅
  - 서로 다른 타입의 주소(참조) 캐스팅
  - 정수 <-> 주소 사이의 캐스팅
- 용도 외의 casting은 error

```c++
#include <iostream>

int main()
{
	int n = 10;

//	char* p1 = static_cast<char*>(&n); // error
	char* p2 = reinterpret_cast<char*>(&n); // ok

//	char& r1 = static_cast<char&>(n); // error
	char& r2 = reinterpret_cast<char&>(n); // ok

	// 정수 <=> 주소
//	int* p3 = static_cast<int*>(1000); // error
	int* p4 = reinterpret_cast<int*>(1000); // ok

	double d = reinterpret_cast<double>(3);
}
```

# const_cast
- 객체(변수)의 <r>상수성 제거</r>하는 캐스팅

```c++
int main()
{
	const int c = 10;

	int* p1 = static_cast<int*>(&c); // error
	int* p2 = reinterpret_cast<int*>(&c); // error
	int* p3 = const_cast<int*>(&c); // ok

//	*p3 = 20;
}
```

# 4개의ㅣ C++ Explicit Casting

|||
|--|--|
|static_cast|논리적이고 이성적인 캐스팅|
|reinterpret_cast|메모리의 재해석|
|const_cast|상수성 제거|
|dynamic_cast|상속 관계에서 안전한 Down Casting, <r>RTTI 강좌</r>참고|


[예]
```C++
int main()
{
	const int c = 10;

	char* p1 = (char*)&c;

	// 위 코드와 동일하게 동작하는 캐스팅 코드를 C++로 작성해 보세요
//	char* p2 = reinterpret_cast<char*>(&c); // error. const 제거 안됨
//	char* p2 = const_cast<char*>(&c);       // error. int* => char* 안됨

	char* p2 = reinterpret_cast<char*>( const_cast<int*>(&c) );
	char* p3 = const_cast<char*>( reinterpret_cast<const char*>(&c) );
}
```
