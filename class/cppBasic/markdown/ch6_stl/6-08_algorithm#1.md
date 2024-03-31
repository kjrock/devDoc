<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 컨테이너에서 검색 기능을 제공하는 방법
- 방법1. 멤버 함수 find를 제공
  - 장점: 사용하기 쉽다.
  - 단점: 동일한 기능을 하는 함수를 모든 컨테이너에 넣어야 한다. 새로운 함수를 추가하려면 모든 컨테이너에 추가해야 한다.
- 방법2. 멤버함수가 아닌 일반함수(템플릿)형태로 find를 제공하자
  - 장점: 한개의 함수(템플릿)로 모든 컨테이너에서 검색할수 있다.
  - 단점: 코드가 좀 복잡해 보인다.

```c++
#include <algorithm>
#include <vector>
#include <list>

int main()
{
	std::list   s = {1, 2, 3, 4, 5};
	std::vector v = {1, 2, 3, 4, 5};

	// 각 컨테이너 에서 3을 검색 하고 싶다.
	auto ret1 = std::find(s.begin(), s.end(), 3);
	auto ret2 = std::find(v.begin(), v.end(), 3);
}
```

## std::find는 전달된 인자가 list 반복자인지 vector의 반복자인지 어떻게 알수 있을까?
- 알수 없다.
  - 모든 반복자는 다음으로 이동하는 방법이 동일하다.

## 알고리즘 (algorithm)
- <r>문제를 해결하는 방법</r> 이라는 용어

## STL 라이브러리에서 알고리즘 (algorithm)
- `std::find` 와 같은 <r>특정 기능(검색, 정렬 등)을 구현한 맴버가 아닌 일반 함수(템플릿)</r>을 가리키는 용어
- `<algorithm>` 헤더 필요
- C++ 표준에 정렬, 검색, 순열, 치환 다양한 알고리즘이 제공됨. 사용법은 대부분 유사

## 알고리즘의 2가지 형태
- 인자로 <r>반복자 전달</r>
- 인자로 <r>컨테이너 전달</r> (C++20부터 지원)

## 반복자 버전
- STL 처음(C++98)부터 지원
- `std::` 이름 공간안에 제공
- 컨테이너의 전체 또는 일부 구간 검색 가능<br>`auto ret = std::find(first, last, 3);`
- last 는 검색 대상 아님.
- `[first, last)` 로 표기
- 검색 실패시 `last` 반환

## 반환값
|||
|--|--|
|검색 성공|해당 요소의 위치를 가리키는 반복자|
|검색 실패|2번째 인자로 전달한 last 반환|


```c++
#include <print>
#include <algorithm>
#include <vector>
#include <list>

int main() {
	std::list s = {1, 2, 3, 4, 5};			
	auto ret1 = std::find(s.begin(), s.end(), 3);

	if ( ret1 == s.end() ) {}  // 실패.!

	auto first = s.begin();
//	auto last  = first + 3; // vector 반복자는 가능, list 반복자는 안됨.
	auto last  = std::next(first, 3);	// 4를 가리킴.
//	auto ret2 = std::find(first, last, 3);
	auto ret2 = std::find(first, last, 4);

	if (ret2 == last ) {
		std::println("fail");
	} else {
		std::println("success : {}", *ret2);
	}
}
```

## 컨테이너 버전
- C++20 부터 지원
- std::ranges 이름 공간안에 제공 <br>`auto ret = std::ranges::find(cont, 3);`
- 검색 실패시 `const.end()` 반환
- 부분 검색하려면 `views` 사용

```c++
#include <print>
#include <algorithm>
#include <vector>
#include <list>
#include <ranges>

int main()
{
	std::list s = {1, 2, 3, 4, 5};
	auto ret1 = std::ranges::find(s, 3);

	if ( ret1 == s.end()) {}

	auto iv = std::views::take(s, 2);
	auto ret2 = std::ranges::find(iv, 3);

	if (ret2 == iv.end() )
		std::println("fail");
	else 
		std::println("success : {}", *ret2);
}
```