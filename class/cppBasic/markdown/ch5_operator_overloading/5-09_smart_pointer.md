<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 스마트 포인터 (smart pointer)
- 다른 타입의 포인터 역할을 하는 객체
- p 자체는 포인터가 아닌 Ptr 타입의 객체
- Car*를 보관할수 있는 멤버 데이터를 가짐.

```c++
class Car 
{
	int color;
public:
	~Car()    { std::println("~Car");  }
	void go() { std::println("Car Go");}
};

class Ptr 
{
	Car* obj;
public:
	explicit Ptr(Car* p = nullptr) : obj{p} {}
	~Ptr() { delete obj;}
	Car* operator->() { return obj;}
	Car& operator*()  { return *obj;}
};

int main()
{
//	Car* p = new Car; // 사용후 delete 해야 한다.
	Ptr p( new Car );  // p는 객체, 타입 Ptr

	// Ptr의 객체 p가 Car* 역활을 수행
	p->go();	// p.operator->()go()
				// (p.operator->())->go()
	(*p).go();	// (p.operator*()).go()
}
```

## 스마트 포인터의 원리
- `-> 연산자`와 `* 연산자`를 재정의해서 객체를 포인터처럼 사용가능하게 만든 것
- <r>주의!! * 연산자를 반드시 reference로 반환해야 한다.</r> (임시객체가 생성 안되게 하기 위해)

## 왜 raw pointer를 사용하지 않고 smart pointer를 사용하는가?
- 스마트 포인터는 객체이므로 <r>생성/복사/대입/소멸의 모든 과정에서 추가 작업</r>을 수행할수 있다.
- 대표적인 활용이 <r>소멸자에서 객체 자동 삭제</r> 기능

## std::shared_ptr
- C++ 표준에서 제공하는 스마트 포인터
- `<memory>` 헤더

```c++
#include <memory>

class Car 
{
	int color;
public:
	~Car()    { std::println("~Car");  }
	void go() { std::println("Car Go");}
};

int main()
{
//	std::shared_ptr<Car> sp1 = new Car; // error
	std::shared_ptr<Car> sp2(new Car);  // ok
	std::shared_ptr<Car> sp3{new Car}; 	// ok

	sp2->go();
}
```



