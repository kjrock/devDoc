<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## noexcept 키워드의 2가지 용도
1) 함수가 예외가 있는지 없는지 조사
   - noexcept operator (연산자)
2) 함수가 예외가 없음을 표기
   - noexcept specifier (지정자)

## 함수가 예외 가능성 여부를 조사하는 방법
`bool b = noexcep(함수 호출 표현식);`
- 함수가 예외가 없음을 알리려면 <r>함수 선언 뒤에 noexcept를 붙인다. </r>

```c++
#include <print>

void f1() noexcept { }
void f2(int a, int b) noexcept { }
void f3(int a, int b) { throw 1; }

int main()
{
	bool b1 = noexcept( f1() );
	bool b2 = noexcept( f2(1, 2) );
	bool b3 = noexcept( f3(1, 2) );

	std::println("{}", b1);
	std::println("{}", b2);
	std::println("{}", b3);
}
```

## 함수가 예외가 없음을 표기하는 방법
|||
|--|--|
|f()|예외가 발생할수 있음|
|f() noexcept|예외 없음|
|f() noexcept(true)|예외 없음|
|f() noexcept(false)|예외가 발생할수 있음|

```c++
#include <print>

void f1() noexcept {}

void f2(int a) noexcept {}
void f2(double a) {}

template<typename T>
void foo(T arg) noexcept( noexcept(f2(arg)) )
{
	f1();
	f2(arg);
}

int main()
{
	std::println("{}", noexcept(foo(3)));
	std::println("{}", noexcept(foo(3.4)));
}
```

## noexcept 붙은 함수에서 예외가 발생하면 
- <r>std::terminate</r> 호출

## 왜 예외가 없음을 알리는가?
- 예외 여부에 따라 최적화된 코드를 작성할수 있다.
- std::move_if_noexcept()
