<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# C 방식 캐스팅의 문제점
- 논리적으로 위험한 캐스팅 코드도 대부분 허용
- 위험한 캐스팅이 <r>개발자의 실수인지 의도된 것인지 구분하기 어렵다.</r>

# void* ==> 다른 타입으로 캐스팅
- 위험하기 보다는 프로그램 개발시 <r>반드시 필요한 캐스팅</r>


# int* ==> 다른 타입(double*)로 캐스팅
- int 주소를 double* 변수에 담는 것은 위험하다
- 개발자가 의도한 캐스팅인지 일수인지?

# 상수 변수 주소를 비 상수를 가리키는 포인터로 캐스팅


# C++ explicit casting
- 용도에 맞게 사용하기 위해 4개의 캐스팅 방법 제공

|||
|--|--|
|static_cast|converts between types using a combination of implicit and user-defined conversions|
|reinterpret_cast|converts between types by reinterpreting the underlying bit pattern|
|const_cast|converts between types with differenct cv-qualification|
|dynamic_cast|safely converts pointers and references to classes up, down and sideways along the inheritance hierarchy|

# static_cast
- 논리적으로 맞고, 반드시 필요한 경우의 캐스팅만 허용
- 대부분의 프로그램은 이 캐스팅을 사용해야 한다.

## void* ==> 다른 타입 포이터
## primitive type간의 값 캐스팅
## 상속 관계 타입 간의 캐스팅
## 사용자 정의 변환 연산자나 변환 생성자가 있는 경우
## static_cast가 허용하지 않는 캐스팅의 경우, 해당 기능을 수행하는 다른 캐스팅 방법 사용
  
```c++
#include <cstdlib>

int main()
{
//	int* p1 = (int*)malloc(100);// ok
	int* p1 = static_cast<int*>(malloc(100));// ok
	free(p1);

	int n = 10;
//	double* p2 = (double*)&n;  // ok
	double* p2 = static_cast<double*>(&n);
						// error

	const int c = 10;
//	int* p3 = (int*)&c; 	   // ok
	int* p3 = static_cast<int*>(&c);
						// error
}
```