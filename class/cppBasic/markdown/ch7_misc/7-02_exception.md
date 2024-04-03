<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 예외(exception) 이란?
- 객체지향 언어에서 많이 사용하는 오류 처리 방식

## 예외 문법을 사용하는 방법
1) 함수 실패시 `throw` 키워드를 사용해서 예외를 전달한다.
    - <r>던진다(throw)</r> 라고 표현히기도 함.
    - throw 를 하면 함수는 더 이상 실행되지 않고, 호출자의 catch 문으로 이동
2) `try`, `catch` 키워드를 사용해서 던져진 예외를 잡는다.
3) 호출자가 던져진 예외를 처리하지 않으면 프로그램은 종료된다.
    - `abort()` 함수가 호출된다.

```c++
int db_backup()
{
	if ( 1 )  // 실패라고 가정.
		throw 1;

	std::println("continue db_backup");

	return 0;
}

int main()
{
	int ret = db_backup();

	std::println("continue main");
}
```

## 특징
- <r>함수 반환값과 오류의 전달이 완벽히 분리된다.<r/>
- <r>호출자는 반드시 오류를 처리해야만 한다.</r>

## 던져진 예외를 처리하는 방법

```c++
#include <print>

int db_backup()
{
   // 테스트를 위해, 강제로 예외 발생
	if ( 1 )  
		throw 1;

	std::println("continue db_backup");
	return 0;
}

int main()
{
	try
	{
      // 예외 발생 가능성이 있는 함수를 호출할때는 try{} 안에서 호출
      // 예외 발생시 catch로 이동
		int ret = db_backup();
      // 이 부분은 db_back에서 예외가 없을 때만 실행

	}
	catch(int e)
	{
      // 예외가 발생된 경우만 실행
		std::println("exception!!");
	}

   // 이 부분은 항상 실행됨.
	std::println("continue main");
}
```
## 오류 발생시 오류에 대한 자세한 정보를 호출자에게 전달하는 것이 좋다.
- 오류에 대한 자세한 정보를 담은 <r>타입을 설계해서 객체를 반환</r> 한다.
- 자세한 정보가 없어도 <r>클래스 이름만으로도 가독성이 좋아진다.</r>

## C++ 표준도 일부함수(맴버 함수)가 실패하면 예외를 던진다.
- C++ 표준의 <r>예외 전용 클래스</r>가 있다.
- cppreference.com 참고

## 함수는 여러가지 이유로 실패할수 있다.
- <r>여러개의 catch</r> 문장을 만들수 있다

## cactch(...)
- 모든 종류의 예외를 잡을수 있다.
- 반드시 마지막에 놓아야 한다.


```c++
#include <print>

class file_not_found {};
class network_disconnected {};
class authentication_failed {};

int db_backup()
{
	if ( 1 )  
		throw file_not_found{};

	if ( 2 )  
		throw network_disconnected{};

	if ( 3 )  
		throw authentication_failed{};

	// ...... 

	return 0;
}

int main()
{
	try
	{
		int ret = db_backup();
	}
	
	catch(const file_not_found& e)
	{
		std::println("file_not_found!!");
	}
	catch(const network_disconnected& e)
	{
		std::println("network_disconnected!!");
	}	
	catch(...)
	{
		std::println("...");
	}
}
```