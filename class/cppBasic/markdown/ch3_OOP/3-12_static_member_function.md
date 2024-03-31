<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## static member data
- 객체가 생성되지 않아도 메모리에 존재한다.

## member function
- 호출하려면 반드시 객체가 있어야 한다.

## <r>객체없이 private 맴버인 static Car::count에 접근</r>할수 없을까?
- <r>객체없이 호출가능한 멤버 함수</r>가 필요하다.
- static member function

## static member function
- <r>객체없이 호출 가능</r>한 맴버 함수
- <r>객체 이름</r> 또는 <r>클래스 이름</r>으로 접근 가능

|||
|--|--|
|객체 이름으로 접근|c1.get_count();|
|클래스 이름으로 접근|Car::get_count();  // <r>권장</r>|

```c++
#include <iostream>

class Car
{	
	int speed{0};
	static int count;
public:
	Car()  {++count;}
	~Car() {--count;}

	static int get_count() { return count;}
};
int Car::count{0};

int main()
{
	// 여기서 Car 객체의 갯수를 알고 싶다.
	std::cout << Car::get_count() << std::endl; 

	Car c1;
	Car c2;
//	Car::count = 100;                           // error
//	std::cout << Car::count << std::endl;       // error
//	std::cout << c1.get_count() << std::endl;   // ok
	std::cout << Car::get_count() << std::endl; // ok
}
```

## static member data vs global

||메모리 할당|접근 지정자|
|--|--|--|
|전역 변수|프로그램 처음 실행시|x|
|static 멤버 데이터|프로그램 처음 실행시|o|
|non static 멤버 데이터|객체 생성시|o|

- global, static member data => static(data)
- member data => stack or heap

## static member function vs globa function

||호출 가능 시점|private 접근|
|--|--|--|
|일반 함수|객체없이 호출 가능|x|
|static 멤버 함수|객체없이 호출 가능|o|
|non static 멤버 함수|객체 생성후 호출 가능|o|

[예제]
```c++
class Object
{
	int idata;
	static int sdata;
public:
	void ifunc()
	{
		idata = 10;	// 1. ok
		sdata = 10;	// 2. ok
		sfunc();	// 3. ok
	}
	static void sfunc()
	{
		idata = 10;	// 4. error
		sdata = 10;	// 5. ok
		ifunc();	// 6. error
	}
};
int Object::sdata{0};

int main()
{
	Object::sfunc();

	Object obj;
	obj.ifunc();
}
```

- static 멤버 데이터는 객체가 없어도 메모리에 생성된다.
- static 맴버 함수는 객체가 없이 호출 가능하다.

## 핵심
- <r>static 멤버 함수에서는 static 멤버(데이터, 함수)만 접근</r> 할수 있다.

## 선언과 구현의 분리

|||
|--|--|
|static member data|외부 정의는 <r>구현 파일에 만들어야</r> 한다.|
|static member function|static 키워드는 <r>함수 선언부에만 표기</r>해야 한다.|
