<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 예외와 성능
- 예외처리를 위해 생성되는 기계어 코드가 오버헤드가 있다.
- 성능이 중요한 분야에서는 예외를 사용하지 않는 경우가 있다.
- C#, Java, Python 등의 언어에서는 예외를 많이 사용

## C++ 표준의 일부 함수가 예외를 발생시킨다.

## std::stoi()
- `<string>` 헤더
- 인자로 전달된 문자열을 정수로 변경해서 반환하는 함수
- 정수로 변경할수 없는 문자열을 전달하면 `std::invalid_argument` 타입의 예외 발생

## std::exception
- 모든 C++ 예외 클래스는 `std::exception` 이라는 클래스로부터 파생된다.
- 모든 예외 타입에는 `what` 가상함수가 있다.

```c++
#include <print>
#include <string>

int main()
{
	try
	{
		int n = std::stoi("KK");

		std::println("result : {}", n);
	}
//	catch( const std::invalid_argument& e)
//	catch(...)
	catch( const std::exception& e)
	{
		std::println("what : {}", e.what());
	}
}
```

## std::vector 의 요소 접근
|||
|--|--|
|[]|잘못된 인덱스 전달시 <r>undefined behavior</r>|
|at()|잘못된 인덱스 전달시 <r>std::out_of_range</r> 타입의 예외 발생|


```c++
#include <print>
#include <vector>

int main()
{
	std::vector v = {1, 2};

	try
	{
		v[100] = 0;
	//	v.at(100) = 0;
	}
	catch( const std::out_of_range& e)
	{
		std::println("what : {}", e.what());	
	}

	std::println("continue main");
}
```