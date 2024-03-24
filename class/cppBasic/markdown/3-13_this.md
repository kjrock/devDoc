<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 멤버 데이터는 객체당 한개씩 생성된다.
## 멤버 함수는 코드 메모리에 한개만 만들어져 있다.<br> 즉, 객체가 여러게 생성되어도 멤버 함수는 한개만 있다.

## 함수 인자는 2개(a, b) 밖에 없는데 x가 어떤 객체의 멤버인지 어떻게 알수 있는가?
- <r>멤버 함수 호출시, 객체의 주소가 같이 전달</r>된다.
- <r>this call</r> 이라고 한다.

[원래 소스]
```c++
#include <iostream>

class Point
{
	int x{0};
	int y{0};
public:
	void set(int a, int b) {
		x = a;
		y = b;	
	}
};

int main() {
	Point pt1;
	Point pt2;

	pt1.set(10, 20);
	pt2.set(10, 20);

//	set(&pt1, 10, 20);  // error, 이렇게 명시적으로 호출은 안됨.
}
```
[컴파일러가 변경한 코드]
```c++
#include <iostream>

class Point
{
	int x{0};
	int y{0};
public:
	void set(Point* this, int a, int b)	{
		this->x = a;
		this->y = b;	
	}
};

int main() {
	Point pt1;
	Point pt2;

	set(&pt1, 10, 20);
	set(&pt2, 10, 20);	
}
```

## 주의!!!
- 실제 함수 인자가 전달되는 방식과 객체 주소가 전달되는 방식은 약간의 차이가 있다.
- (32bit / 64bit 환경, 컴파일러에 따라서도 차이가 있음)


## this
- 멤버 함수 안에서 사용 가능한 키워드
- 해당 멤버 함수를 호출할때 사용한 <r>객체의 주소</r>
- static 멤버 함수에서는 this를 사용할수 없다.

## this가 사용되는 경우
- 멤버 데이터임을 명확히 하고 싶을때
- 멤머 함수가 this 또는 *this를 반환하면, <r>멤버함수를 연속적으로 호출</r>할수 있다.
  - [참고] <r>*this</r>를 반환하는 경우 반드시 <r>참조로 반환</r>해야 한다.


```c++
class Counter
{
	int count{0};
public:
	void reset(int count = 0) {
		this->count = count;
	}
	Counter* increment() {
		++count;
		return this;
	}
	Counter& decrement() {
		--count;
		return *this;
	}
};
int main() {
	Counter c;	
	c.increment()->increment()->increment();
	c.decrement().decrement().decrement();
}
```


