<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## `std::endl` 의 원리
- `std::endl`은 함수이다.
- `operator<<(함수 포인터)` 로 전달 받아서 다시 endl 함수로 호출하는 원리

## std::endl뿐 아니라 std::hex, std::dec 등도 모두 함수
- <r>입출력 조정자 함수 (io manipulator)</r>
- 사용자가 <r>새로운 조정자 함수를 추가</r>할수도 있다.

## 성능
- `std::endl`을 사용하는 것보다 `\n`을 사용하는 것이 빠르다.



```c++
#include <stdio.h>

namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int    arg) { printf("%d", arg); return *this;}
		ostream& operator<<(char   arg) { printf("%c", arg); return *this;}
		ostream& operator<<(const char* arg) { printf("%s", arg); return *this;}
		ostream& operator<<(void*  arg) { printf("%p", arg); return *this;}

		ostream& operator<<(ostream&(*f)(ostream&))
		{
			 f(*this); // endl(cout), tab(cout)
			 return *this;
		}
	};
	ostream cout;

	ostream& endl(ostream& os)
	{
		os << '\n';
		return os;
	}
}

std::ostream& tab(std::ostream& os)
{
	os << '\t';
	return os;
}

std::ostream& menu(std::ostream& os)
{
	os << "1. AAA\n";
	os << "2. BBB\n";
	return os;
}

int main()
{	
	std::endl( std::cout ); 
	std::cout << std::endl; // cout.operator<<(endl 즉, 함수포인터)
	std::cout << "A" << tab << "B" << std::endl;
	std::cout << menu;
}

```