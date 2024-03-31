<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## std::cout으로 사용자 정의 타입의 객체를 출력하려면
- operator<<(std::ostream, Point) 함수를 제공해야 한다.
- operator<< 는 non-const member funtion이다. 첫번째 인자를 받을때 const를 붙이면 operator<<를 사용할수 없다.
- 상수 사용자 객체를 출력할수 있게, 두번째 인자는 const로 받아야 한다.
```c++
std::ostream& operator<<(std::ostream& os, const Point& pt) {}
```


```c++
#include <iostream>

class Point
{
	int x{0};
	int y{0};
public:
	Point(int x, int y) : x{x}, y{y} {}	

	friend std::ostream& operator<<( std::ostream& os, const Point& pt);
};

std::ostream& operator<<( std::ostream& os, 
						  const Point& pt)
{
	return os << pt.x << ", " << pt.y;
}


int main()
{
	Point p{1, 2};
	std::cout << p; 	// cout.operator<<(Point) 처럼 멤버로 추가는 안됨
						// operator<<(cout, p)
	std::cout << 1;		// cout.operator<<(int)	
	std::cout << 3.4;   // cout.operator<<(double)
}
```

## Point가 Graphics 라는 이름 공간안에 있다면
- operator<<(std::ostream, Point) 함수도 같은 이름 공간에 넣어도 실행하는데 문제 없다.
- 어떻게 가능할까?
- ADL 강좌 참조