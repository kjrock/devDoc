<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## capacity vs size
- capacity : container의 실제 메모리 크기
- size : container의 논리적인 크기

```c++
#include <print>
#include <vector>

void check(const std::vector<int>& v) {
	std::println("capacity : {}, size : {}", v.capacity(), v.size() );				 
}

int main() {
	std::vector v = { 1, 2, 3, 4, 5 };

	v.resize(3); 
	check(v);	// c : 5    s : 3
	v.push_back(0);	// capacity > size 이므로
					// 빠르게 동작 
	check(v);	// c : 5   s : 4
	v.shrink_to_fit();		
	check(v);	// c : 4   s : 4
	v.push_back(0); // capacity == size  이므로 메모리 재할당 필요
					// 느리다.
	check(v);	// c : ?   s : 5
	v.clear();	// 메모리를 제거하지는 않음.
				// size 만 0으로
	check(v);
	v.resize(0); // 또는 v.clear()
	v.shrink_to_fit();
	check(v);
}
```
- `resize(3)`, `clear()`
  - 실제 메모리를 줄이지 않는다.
  - 실제 메모리를 줄이려면 `shrink_to_fit()` 멤버함수 사용

```c++
#include <print>
#include <vector>

void check(const std::vector<int>& v) {
	std::println("capacity : {}, size : {}", v.capacity(), v.size() );				 
}

int main() {
	std::vector<int> v1;	// capacity : 0    size : 0
	check(v1);			

	std::vector<int> v2(5);	// capacity : 5    size : 5
	check(v2);	

	std::vector<int> v3;
	v3.reserve(5);			// capacity : 5    size : 0
	check(v3);	
}
```

- capacity: 주로 vector(연속형 container)에서 사용
