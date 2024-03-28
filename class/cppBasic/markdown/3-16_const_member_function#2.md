<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## Rect 클래스의 getArea() 멤버 함수는 객체의 상태를 변경하지 않으므로 <r>상수 멤버 함수</r>가 되어야 한다.

## 디버깅 등의 목적으로 객체당 getArea()가 몇번 호출되었느지 알고 싶다.

## <r>mutable</r> 멤버 데이터
- 상수 멤버 함수에서도 값을 변경할수 있다.

```c++
#include <iostream>

class Rect
{
	int x, y, w, h;
	mutable int cnt = 0;
public:
	Rect(int x, int y, int w, int h)
		: x{x}, y{y}, w{w}, h{h} { } 

	int getArea() const 
	{
//		static int cnt = 0;
		++cnt;
		std::cout << cnt << std::endl;
		return w * h;
	}
};

int main()
{
	Rect r1(1,1,10,10);
	Rect r2(1,1,10,10);

	r1.getArea();
	r2.getArea();
	r2.getArea();
}
```

## 동일 이름의 <r>상수 멤버 함수와 비상수 멤버 함수를 동시에 만들수 있다.</r>
|||
|--|--|
|상수객체|상수멤버 함수만 호출할수 있다.|
|비상수객체|1) 비상수 멤버 함수를 호출<br>2)비상수 멤버함수가 없으면 상수 멤버 함수 호출|

```c++
#include <iostream>

class Number
{
	int value;
public:
	Number(int n) : value(n) {}

	int& get()       { return value;} // 1, 참조 리턴, lvalue 가능
	int  get() const { return value;} // 2, 임시 객체 리턴, lvalue 불가능
};
int main()
{
	Number num(10);
	const Number cnum(10);

	cnum.get(); // 2번만 가능
	num.get();  // 1번 호출, 없다면
				// 2번 호출.

	num.get() = 20;  // ok
	cnum.get() = 20; // error
}
```

## 클래스를 선언과 구현 파일로 분리할때
- <r>const 키워드는 멤버함수 선언과 구현에 모두 표기해야 한다.</r>

