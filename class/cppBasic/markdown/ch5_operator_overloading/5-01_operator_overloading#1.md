<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 연산자 재정의 (operator overloading) 개념
- <r>사용자 정의 타입의 객체에 대해서도 +, - 등의 연산자를 사용</r>할수 있게 하는 문법

## a + b를 컴파일러가 해석하는 방법
- a, b가 모두 <r>primitive  type(int, double 등)</r>인 경우
  - 미리 <r>정해진 방식</r>으로 덧셈 수행
- <r>a, b 중 한개라도 사용자 정의타입</r>이 있는 경우
  - operator+ 라는 이름을 가진 약속된 함수를 호출
  - operator+ 함수를 찾을 수 없는 경우, <r>+ 연산을 할수없다</r>는 에러 발생

```c++
class Point
{
	int x{0};
	int y{0};
public:
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}
};

int main()
{
	Point p1{1, 1};
	Point p2{2, 2};

	int   n1 = 10 + 20;	// ok
	Point p3 = p1 + p2;	// ?
}
```

## p1 + p2 코드를 컴파일러가 해석하는 방법
- operator+(p1, p2) 함수 또는
- p1.operator+(p2) 함수를 찾게 된다.

## operator+를 만드는 2가지 방법
|||
|--|--|
|멤버가 아닌 함수로 구현| operator+(p1, p2)<br>함수 인자는 2개|
|멤버 함수로 구현| p1.operator+(p2)<br>함수 인자는 1개|


## 방법1. 멤버가 아닌 함수로 구현
```c++
class Point
{
	int x{0};
	int y{0};
public:
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}

	friend Point operator+(const Point& p1, const Point& p2);
};

Point operator+(const Point& p1, const Point& p2)
{
	Point pt{p1.x + p2.x, p1.y + p2.y};
	return pt;
}
```
## 멤버가 아닌 함수에서 멤버 데이터인 x, y에 접근하려면
- x, y를 public 영역에 선언
- get_x(), get_y() 멤버 함수 제공
- <r>operator+ 를 friend 함수로 등록</r>

## 방법2. 멤버 함수로 구현하는 operator+ 함수
- `+` 연산자는 이항 연산자이지만 operator+ 멤버 함수의 <r>인자는 1개</r>
- 상수 객체도 덧셈을 할수 있어야 하므로 <r>const member function</r>으로 구현

```c++
class Point
{
	int x{0};
	int y{0};
public:
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}

	Point operator+(const Point& p) const
	{
		Point pt{p.x + x, p.y + y};
		return pt;
	}
};
```

## 멤버 함수와 멤버가 아닌 함수를 모두 제공하면 
- 컴파일 에러 발생
- 반드시 둘중 한개만 제공해야 한다.

## 멤버 함수 vs 멤버가 아닌 함수
- private 멤버 접근하기에는 멤버함수가 좋다.
- 하지만 1번째 인자가 사용자 정의 타입이 아닌 경우는 멤버함수로 만들수 없는 경우가 있다.

||멤버 함수|멤버가 아닌 함수|
|--|--|--|
|p1 + p2|p1.operator+(Point)|operator+(Point, Point)|
|p1 + n1|p1.operator+(int)|operator+(Point, int)|
|n1 + p1|만들수 없다.|operator+(int, Point)|

```c++
int main()
{
	int n1 = 10;
	Point p1{1, 1};
	Point p2{2, 2};

	Point ret1 = p1 + p2; // p1.operator+(Point) 
	Point ret2 = p1 + n1; // p1.operator+(int) 
	Point ret3 = n1 + p1; // n1.operator+(Point)
						  // error. 
}
```