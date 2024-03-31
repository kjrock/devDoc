<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# Constructor / Desctructor
## 모든 멤버 데이터가 public 영역에 있으면
- 객체 생성시 구조체 초기화 문법({}사용)으로 멤버를 초기화할 수 있다.

```c++
#include <iostream>
#include <string>

class Person
{
public:
	std::string name;
	int         age;
};

int main()
{
	Person p = {"kim", 25};
}
```

## 멤버 데이터가 private 영역에 있으면
- 구조체 초기화 문법을 사용할수 없다.
- 멤버를 초기화하는 멤버 함수를 제공해야 한다.
- 객체 생성시 초기화 함수를 자도응로 호출되게 할수 없을까?

## 생성자와 소멸자

|||
|--|--|
|생성자(constructor)|<r>클래스이름()</r> 모양의 함수<br>객체를 생성할때 자동으로 호출되는 함수|
|소멸자(destructor>|<r>~클래스이름()</r> 모양의 함수<br>객체가 파괴될때 자동으로 호출되는 함수|

```c++
#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	int         age;

public:
	Person() {
		name = "kim";
		age = 20;
		std::cout << "Constructor"
						 << std::endl;
	}
	~Person() {
		std::cout << "Destructor" << std::endl;
	}
};

int main() {
//	Person p = {"kim", 25};  //error
	Person p;

	std::cout << "____" << std::endl;

}
```

## 생성자 특징
- 클래스 이름과 동일한 이름의 함수
- 반환 타입을 표시하지 않고, 값을 반환 할 수 없다.
- 인자가 없어도 되고 있어도 된다.
- 2개 이상 만들 수 있다.
- 객체를 생성하면 자동으로 생성자가 호출된다.
  - <r>생성자가 있어야 객체를 생성할수 있다.</r>

```c++
class Point
{
	int x;
	int y;
public:
	Point() 			{ x = 0; y = 0; }
	Point(int a, int b) { x = a; y = b; }	
};
```

## 디폴트 생성자(default constructor)
- 인자가 없는 생성자
- <r>사용자가 생성자를 한개도 만들지 않으면 컴파일러가 디폴트 생성자를 제공</r>한다.

```c++
#include <iostream>

class Point
{
	int x;
	int y;
public:
};

int main()
{
	Point p1;       // ok
//	Point p2(1,2);  // error
}
```

[다양한 경우의 생성자 호출]
```c++
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() 			{ x = 0; y = 0; std::cout << "ctor1" << std::endl;}
	Point(int a, int b) { x = a; y = b; std::cout << "ctor2" << std::endl;}	
};
int main()
{
	Point p1;		// 1번
	Point p2(1,2);	// 2번
	Point p3{1,2};  // 2번,  C++11
	Point p4 = {1,2};// 2번, C++11

	Point arr1[5];	// 1번, 5회
	Point arr2[5] = { {1,2}, {1,1} };  // 2번 2회, 1번 3회

	Point* p; // 객체 생성 아님. 생성자 호출 안됨.

	p = static_cast<Point*>(malloc(sizeof(Point))); // 생성자 호출 안됨
	free(p);

	p = new Point;		// 1번
	delete p;

	p = new Point(1,2); // 2번
	delete p;
}
```

## class 안에 class가 있을때 호출 순서
- 객체 생성시, 멤버의 생성자가 먼저 실행되고 객체 자신의 생성자가 호출된다.
  - ptFrom 생성자 호출
  - ptTo 생성자 호출
  - rc 생성자 호출


```c++
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() 			{ x = 0; y = 0; std::cout << "Point()"         << std::endl;}
	Point(int a, int b) { x = a; y = b; std::cout << "Point(int, int)" << std::endl;}	
};

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	Rect() { std::cout << "Rect()" << std::endl; }
};
int main()
{
	Rect rc;
}
```
