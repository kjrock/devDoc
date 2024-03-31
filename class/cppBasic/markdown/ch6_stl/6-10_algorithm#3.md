<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## STL 의 모든 알고리즘 학습하려면
- `cppreference.com`의 첫번째 화면에서 `algorithm library` 참고

## 아래처럼 동작하는 프로그램을 만들어 보세요.
1. `-1`을 입력할때까지 입력을 받아서 `vector`에 보관하세요. 입력이 종료되면  vector 내용 출력.
   - `push_back` 멤버함수 사용
2. 입력한 값중 10보다 큰 값은 모두 0으로 변경해 주세요. vector 내용 출력.
   - `replace`, `replace_if` 알고리즘
3. 모든 요소의 합을 구해서 출력해 주세요.
	- `accumulate` 알고리즘
4. vector의 모든 요소를 내림차순 정렬해서 출력하세요.
	- `sort` 알고리즘, 조건자
5. vector의 모든 요소를 1로 채워서 출력해 보세요.
	- `fill` 알고리즘


```c++
#include <print>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	// 1. 
	std::vector v = { 1, 3, 10, 30, 4, 7, 8, 20};

	for (auto e : v) 
		std::print("{}, ", e);
	std::println("");


	// 2.
	//std::replace(v.begin(), v.end(), 3, 0);
	std::replace_if(v.begin(), v.end(), [](int n) { return n >= 10;}, 0);

	for (auto e : v) 
		std::print("{}, ", e);
	std::println("");

	// 3. 
	int n = std::accumulate(v.begin(), v.end(), 0);
	std::println("{}, ", n);


	// 4. 
//	std::sort(v.begin(), v.end());
	std::sort(v.begin(), v.end(), [](int a, int b) { return a > b;} );

	for (auto e : v) 
		std::print("{}, ", e);
	std::println("");

	// 5. 
	std::fill(v.begin(), v.end(), 1);

	for (auto e : v) 
		std::print("{}, ", e);
	std::println("");

}
```