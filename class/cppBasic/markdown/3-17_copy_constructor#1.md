<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 복사 생성자 (copy constructor)란?
- 자신과 동일한 타입 한개를 인자로 가지는 생성자

## 사용자가 복사 생성자를 만들지 않으면
- 컴파일러가 제공
- 디폴트 복사 생성자(default copy constructor)
- 모든 멤버를 복사(bitwise copy)한다.
```c++
Point(const Point& p) : x(p.x), y(p.y) {}
```
 
 ```c++
class Point
{
	int x;
	int y;
public:
	Point()             : x{0}, y{0} {} // 1
	Point(int a, int b) : x{a}, y{b} {} // 2
};

int main()
{
	Point p1;		// ok.
	Point p2(1,2);	// ok
//	Point p3(1);	// error. Point(int) 필요
	Point p4(p2); 	// ok.    Point(Point), compiler가 만든 복사 생성자 사용
}
 ```

```c++
#include <iostream>

class Point
{
public:
    int x;
    int y;
    
    Point(int a, int b) : x(a), y(b) 
    {
        std::cout << "ctor" << std::endl;
    }    
    explicit Point( const Point& p) : x(p.x), y(p.y)
    {
        std::cout << "copy ctor" << std::endl;
    }
};

int main()
{
    Point p1(1,2);   // 생성자
    Point p2(p1);    // 복사 생성자
    Point p3{p1};    // 직접 초기화, 복사 생성자
    Point p4 = {p1}; // 복사 초기화, 복사 생성자
    Point p5 = p1;   // 복사 초기화, 복사 생성자
}
```

# 복사 생성자가 호출되는 3가지 경우
## 1. <r>자신과 동일한 타입의 객체로 초기화 될때</r>
```c++
    Point p2(p1);    // 복사 생성자
    Point p3{p1};    // 직접 초기화, 복사 생성자
    Point p4 = {p1}; // 복사 초기화, 복사 생성자, explicit가 아닌경우만
    Point p5 = p1;   // 복사 초기화, 복사 생성자, explicit가 아닌경우만
```

## 2. <r>함수 인자를 call by value로 받을 경우</r>
- 함수 인자를 const reference로 사용하면 복사본을 만들지 않으므로 복사 생성자가 호출되지 않는다.

## 3. <r>함수가 객체를 값으로 반환할때</r>
- 참조로 반환하면 리턴용 임시객체가 생성되지 않는다.
- 단, 지역변수는 참조로 반환하면 안된다.

