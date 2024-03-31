<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 컨테이너의 모든 요소를 열거하려면
- range - for 사용
- 컨테이너의 요소를 수정하려면 auto가 아닌 auto& 사용

```c++
int main()
{
	std::vector v = {1,2,3,4,5};

//	for( auto e : v)
	for( auto& e : v)
	{
		e *= 2;
	}

	for( auto e : v)
		std::println("{}", e);
}
```

## 컨테이너의 일부 요소만 열거하고 싶다면
  1. C++20에서 추가된 view 개념 사용
  2. legacy for 문과 [] 연산자
  3. legacy for 문과 반복자

```c++
int main()
{
	std::vector v = {1,2,3,4,5};

//	for( auto e : v)
	for( auto e : std::views::take(v, 3) )
	{
		std::println("{}", e);
	}
}

int main()
{
	std::vector v = {1,2,3,4,5};

	auto p = v.begin();

	for (int i = 0; i < 3; i++)
	{
	//	v[i] = 0; // list 안됨.
		*p = 0;   // 모든 컨테이너 가능.
	}
}
```

## views

```c++
#include <print>
#include <vector>
#include <ranges>

//bool foo(int n) { return n % 2 == 0;}

int main()
{
	std::vector v = {1,2,3,4,5,6,7,8,9,10};

//	for( auto e : v)
//	for( auto e : std::views::take(v, 5) )
//	for( auto e : std::views::reverse(v) )
//	for( auto e : std::views::drop(v, 5) )
//	for( auto e : std::views::filter(v, foo ) )
	for( auto e : std::views::filter(v, [](int n) { return n % 2 == 0; } ) )
	{
		std::println("{}", e);
	}
}
```
