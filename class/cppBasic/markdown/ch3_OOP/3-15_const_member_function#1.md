<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 

```c++
#include <iostream>

class Point
{
public:
	int xpos, ypos;

	Point(int x, int y) : xpos{x}, ypos{y} {}

	void set(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void print() {
		std::cout << xpos << ", " << ypos << std::endl;
	}
};

int main() {
//	Point pt(1, 2);
	const Point pt(1, 2);

	pt.xpos = 10;   // error. public 이지만 상수이므로
	pt.set(10, 20); // error. 
	pt.print();     // error
}
```

## print 멤버 함수는 멤버의 값을 변경하는 코드가 없는데 왜 호출할수 없을까?
- 컴파일러는 <r>함수의 선언부를 보고 함수 호출 여부를 결정</r>한다.
- 함수의 선언만으로는 멤버의 값을 변경하는지 알수 없다.

## 상태를 변경할수 없는 상수 객체라도 print() 멤버함수는 호출할수 있어야 되지 않을까?

## 상수 멤버 함수 (const member function)
- 멤버 함수의 괄호() 뒤쪽에 const를 붙이는 문법
- 함수를 선언과 구현으로 분리할 경우 양쪽에 모두 붙여야 한다.
- 상수 멤버 함수에서는 멤버의 값을 변경하지 않겠다는 약속
- 상수 멤버 함수 안에서는 모든 멤버는 상수로 취급된다.
- 멤버의 값을 변경하는 경우 컴파일 에러
- <r>상수 객체는 상수 멤버 함수만 호출할수 있다.</r>

## 상수 멤버 함수는 결국, 상수 객체를 위한 문법입니다. 그런데 상수 객체를 사용하는 경우는 별로 없지 않나요?
=> 아주 많이 사용됨

```c++
class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h)
		: x{x}, y{y}, w{w}, h{h} { } 

//	int getArea() { return w * h;} // 틀린 코드..
	int getArea() const { return w * h;}
};

//void foo(Rect r) // call by value : 복사본 오버헤드
void foo(const Rect& r) {
	int area = r.getArea(); // ????
}

int main() {
	Rect r(1,1,10,10);  // 상수객체 아님.
	int area = r.getArea(); // ok.
	foo(r);
}
```