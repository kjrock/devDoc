<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 레퍼런스 (reference, 참조)
- 이미 존재하는 변수(메모리)에 대한 추가적인 <r>별칭(alias)를 부여</r>하는 문법

# & 연산자

|||
|--|--|
|변수의 주소를 구할때 사용|int n = 0; //변수 선언 후<br>int* p = &n; //변수의 주소를 구할때|
|레퍼런스 변수를 선언할때 사용|int& r = n;|

```c++
#include <iostream>

int main()
{
	int  n = 10;
	
	int* p = &n;

	int& r = n;  // 참조 변수는 반드시 우변 참조하는 변수가 필요함.

	r = 20;

	std::cout << n << std::endl;  // 20
	std::cout << &n << std::endl; // 
	std::cout << &r << std::endl;
}
```

# reference와 함수 인자
- 인자로 전달된 <r>변수의 값을 1 증가하는 함수</r>를 만들고 싶다.

```c++
void inc1(int  n) { ++n;}
void inc2(int* p) { ++(*p);}
void inc3(int& r) { ++r;}

int main()
{
	int a = 10, b = 10, c = 10;

	inc1(a);
	inc2(&b);
	inc3(c);

	std::cout << a << std::endl; // 10
	std::cout << b << std::endl; // 11
	std::cout << c << std::endl; // 11
}
```

# 함수 인자로 reference를 사용하면
- 포인터와 유사하게 전달된 인자의 값을 수정할수 있다.
- 포인터보다 <r>간결하고 안전하게 코드</r>를 작성할수 있다.


# scanf vs std::cin
- 사용자가 입력한 값을 <r>인자로 전달한 변수에 담아 와야한다.</r>

|||
|--|--|
|scanf("%d", &n);|call by pinter|
|std::cin >> n;|call by reference|

# C vs C++ 특징

```c++
#include <iostream>
#include <algorithm>

// C 언어
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// C++
namespace utils
{
	template<class T>
	inline void swap(T& r1, T& r2)
	{
		T temp = r1;
		r1 = r2;
		r2 = temp;
	}
}
int main()
{
	int x = 10, y = 20;

//	swap(&x, &y);
//	utils::swap(x, y);
	std::swap(x, y);    // 표준 swap

	std::cout << x << std::endl; // 20
	std::cout << y << std::endl; // 10
}
```