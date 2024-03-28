<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 핵심 정리
- 함수가 인자로 기반 클래스의 포인터를 받으면
  - 기반 클래스 뿐 아니라 <r>모든 파생 클래스를 전달</r> 받을수 있다.
- <r>기반 클래스 포인터로 파생 클래스의 고유 멤버에 접근할수 없다.</r>
  - 파생클래스의 고유 멤버에 접근하려면 파생 클래스 타입으로 캐스팅(Downcasting) 해야 한다.

## typeid
|||
|--|--|
|가상함수가 없는 객체<br><r>(non polymorphic type)</r>|<r>컴파일 시간</r>에 포인터 타입으로 조사|
|가상함수가 있는 객체<br><r>(polymorphic type)</r>|<r>실행 시간</r>에 타입 조사(가상함수 테이블 등을 사용)|

```c++
#include <iostream>
#include <typeinfo>

class Animal 
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal 
{
public:
    int color;
};

void foo(Animal* p)
{
    //const std::type_info& t = typeid(p);
    const std::type_info& t = typeid(*p);
    std::cout << t.name() << std::endl;
    
    if ( typeid(*p) == typeid(Dog))
    {
        Dog* pDog = static_cast<Dog*>(p);
        pDog->color = 10;
        std::cout << "Dog" << std::endl;
    }
}

int main()
{
    Animal a; foo(&a);
    Dog    d; foo(&d);    
}

```

## upcasting vs downcasting
|||
|--|--|
|upcasting|파생 클래스 포인터르 기반 클래스 타입으로 캐스팅하는 것<br>항상 안전하다.|
|downcasting|기반 클래스 포인터를 파생클래스 타입으로 캐스팅하는 것<br>안전하지 않을수 있다.|

## downcasting과 캐스팅 연산자
|||
|--|--|
|static_cast|잘못된 downcasting을 조사할수 없다.<br>단, 컴파일 시간에 캐스팅을 수행하므로 오버헤드가 없다.|
|dynamic_cast|잘못된 downcasting을 하면 0을 반환<br>실행 시간에 캐스팅을 수행하므로 약간의 오버헤드가 있다.|