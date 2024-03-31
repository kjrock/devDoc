<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## `std::cout`의 원리
- `std::ostream` 타입의 객체
- `operator<<` 연산자 재정의 기술을 사용
- 정확히는 `basic_ostream` 이라는 클래스 템플릿

```c++
template< typename CharT,
		  typename Traits = std::char_traits<Chart>>
class basic_ostream : virtual public std::basic_ios<ChartT, Traints>
using ostream = basic_ostream<char, char_traits<char>>
```

## std::ostream 과 유사한 클래스 만들기
- 화면 출력 기술이 아닌 <r>연산자 재정의 문법을 이해</r>하는 것으로 목표
- 화면 출력 자체는 `printf` 사용
- 실제 basic_ostream의 구현은 매우 복잡(출력 버퍼등 사용)

## 핵심1. `operator<<()` 연산자 함수 제공
- 모든 표준 타입에 대해서 제공

## 핵심2. `<<`을 사용한 연속적인 출력
- operator<<() 함수가 자기 자신을 참조로 반환해야 한다.
- operator<<() 함수는 <r>non-const member function</r>

## 핵심3. std::cout을 상수 참조로 가리키면
- operator<<() 함수를 사용할수 없다.
- std::cout을 함수 인자로 받을때는 non-const reference 를 사용해야 한다.

```c++
#include <stdio.h>

namespace std
{
	class ostream
	{
		// 출력버퍼
	public:
		ostream& operator<<(int    arg) { printf("%d", arg); return *this;}
		ostream& operator<<(char   arg) { printf("%c", arg); return *this;}
		ostream& operator<<(const char* arg) { printf("%s", arg); return *this;}
		ostream& operator<<(void*  arg) { printf("%p", arg); return *this;}
	};
	ostream cout;
}

int main()
{	
	std::cout << 10 << '\t' << 20 << '\n';
	std::cout << 10; // std::cout.operator<<(int)

}
```