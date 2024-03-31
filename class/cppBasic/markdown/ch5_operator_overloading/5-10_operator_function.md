<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 함수객체 (function object) 란?
- <r>() 연산자를 재정의</r> 해서 함수처럼 사용 가능한 객체

```c++
template<typename T>
struct Plus
{
	T operator()(const T& a, const T& b) const {
		return a + b;
	}
};

int main() {
	Plus<int> p;		// p 는 함수가 아니라 객체.
	int n1 = p(1, 2);	// 객체 p를 함수 처럼 사용
						// p.operator()(1, 2)
	int n2 = p.operator()(1, 2);
}
```

## 왜? 함수가 아닌 함수객체를 사용하는가?

## 함수 객체의 장점
- 상태를 가지는 함수
- 클로저 (closure)
- 인라인 치환성
- 이름 충돌 방지(ADL 회피)

# 0 ~ 9 사이의 중복되지 않는 난수를 반환하는 함수를 만드세요..
## 처음에 1을 반환했다면 다음번 호출시에는 다시 1을 반환하면 안된다.
- 1이 반환되었다는 사실을 어딘가에 보관해야 한다.
- 어디에 보관해야 할까?

## 일반함수는 동작이 있지만 상태가 없다.
- 전역변수 등에 보관해야 하는데 전역변수를 사용하는 것은 일반적으로 좋은 코드가 아니다.

## 함수 객체는 동작 뿐아니라 상태도 가질수 있다.

## 함수 객체는 operator() 연산자 함수뿐 아니라 
- <r>멈버 데이터, 생성자</r> 등을 가질수 있다.
- operator() 함수 실행 중 생성된 데어터를 <r>멤버 데이터에 보관</r>할수 있다.

## std::bitset<> template
- 비트를 관리하는 C++ 표준이 제공하는 타입(템플릿)

```c++
#include <print>
#include <cstdlib>
#include <bitset>

class URandom
{	
	std::bitset<10> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle{b} 
	{
		bs.set(); // 10 비트 모두를 1로
	}

	int operator()() 
	{
		if ( bs.none() )
		{
			if ( recycle )
				bs.set();
			else 
				return -1;
		}

		int v = -1;

		while( ! bs.test(v = rand() % 10) );

		bs.reset(v);	

		return v;
	}
};
//URandom urand;
URandom urand(true);


int main()
{
	for ( int i = 0; i < 15; i++)
		std::print( "{}, ", urand() );

	std::println("");
}
```

## c++ 표준이 제공하는 함수 객체

```c++
#include <print>
#include <functional> // C++ 표준에 많은 함수 객체 제공된다.

int main()
{
	std::plus<int>    f1;
	std::minus<int>   f2;
	std::modulus<int> f3; // %

	std::println("{}", f1(10, 3)); // 13
	std::println("{}", f2(10, 3)); // 7
	std::println("{}", f3(10, 3)); // 10 % 3 => 1
}
```