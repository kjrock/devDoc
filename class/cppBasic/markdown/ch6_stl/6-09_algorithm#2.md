<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 값 검색과 조건 검색
|||
|--|--|
|값 검색|std::find(first, last, 값);|
|조건 검색|std::find(first, last, 함수);|

## 조건자 (predicator)
- `bool` 을 반환하는 함수
- `_if` 로 끝나는 알고리즘에 전달되어 정책으로 사용

|||
|--|--|
|단항 조건자|인자가 1개인 조건자|
|이항 조건자|인자가 2개인 조건자|

- `std::find_if` 는 3번째 인자로 단항 조건자를 요구
- 일반함수보다 람다 표현식 권장

```c++
#include <print>
#include <algorithm>
#include <list>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::list s = {1, 9, 5, 7, 3, 8, 10};

	// s 에서 첫 번째 나오는 3을 찾고 싶다.
	auto ret1 = std::find(s.begin(), s.end(), 3);

	// s 에서 첫 번째 나오는 "3의 배수"를 찾고 싶다.
//	auto ret2 = std::find_if(s.begin(), s.end(), foo );
	auto ret2 = std::find_if(s.begin(), s.end(), [](int n) { return n % 3 == 0;} );

	std::println("{}", *ret2);
}
```

- k값을 람다 표현식에 전달하는 방법
```c++
#include <print>
#include <algorithm>
#include <list>

int main()
{
	std::list s = {1, 9, 5, 7, 3, 8, 10};

	// s 에서 첫 번째 나오는 "3의 배수"를 찾고 싶다.
	auto ret1 = std::find_if(s.begin(), s.end(), 
									   [](int n) { return n % 3 == 0;});

	int k = 0;
	std::cin >> k;

	// s 에서 첫 번째 나오는 "k의 배수"를 찾고 싶다.
	auto ret2 = std::find_if(s.begin(), s.end(), 
									   [k](int n) { return n % k == 0;});

}
```




