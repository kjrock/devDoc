<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# default member initializer
## C++11부터 멤버 데이터에 초기값을 지정할수 있다.
## 원리
- 사용자가 작성한 코드를 <r>컴파일러가 아래처럼 변경</r>
  
[작성된 코드]
```c++
#include <iostream>

class Point
{
public:
	int x{0};
	int y{0};

	Point() {}
	Point(int a)        : x{a} {}
	Point(int a, int b) : x{a}, y{b} {}
};

```
[컴파일러가 변경한 코드]
```c++
#include <iostream>

class Point
{
public:
	int x;
	int y;

	Point()             : x{0}, y{0} {}
	Point(int a)        : x{a}, y{0} {}
	Point(int a, int b) : x{a}, y{b} {}
};

```