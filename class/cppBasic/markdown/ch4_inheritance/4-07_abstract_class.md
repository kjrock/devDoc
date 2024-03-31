<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 순수 가상 함수(pure virtual function)
- 구현이 없고, "= 0"으로 끝나는 가상함수

## 추상 클래스(abstract class)
- 순수 가상함수가 한개 이상 있는 클래스

## 추상 클래스의 특징
- 객체를 생성할수 없다.
- 포인터 변수는 만들 수 있다.

```c++
class Shape
{
public:
	virtual ~Shape() {}	

	virtual void draw() = 0;
};

int main()
{
//	Shape  s;	// error	
	Shape* p;	// ok
}
```

## 추상 클래스로부터 파생된 클래스
- 기반 클래스(추상 클래스)가 가진 <r>순수 가상함수의 구현부를 제공하지 않으면 역시 추상 클래스</r> 이다.
- 객체를 생성할수 있게 하려면 반드시 순수 가상함수를 override해서 구현부를 제공해야 한다.


## 추상 클래스의 의도
- 파생 클래스에게 <r>특정 멤버 함수를 반드시 만들라고 지시</r> 하기 위한 것

## 가상함수 vs 순수 가상함수
|||
|--|--|
|가상함수|파생 클래스가 반드시 재정의할 필요는 없다.<br><r>재정의하지 않으면 기본 구현 제공</r>|
|순수 가상함수|<r>파생 클래스가 반드시 구현을 제공해야 한다.</r>|

```c++
class Shape
{
public:
	virtual ~Shape() {}

//	virtual void draw() { std::println("draw Shape"); }
	virtual void draw() = 0;
};

class Rect : public Shape 
{
public:
	void draw() override { std::println("draw Rect"); }
};

int main()
{
	Rect r;
	r.draw();
}
```