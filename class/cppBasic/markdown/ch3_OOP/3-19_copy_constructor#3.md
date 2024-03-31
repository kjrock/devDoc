<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## <r>얕은 복사란?(shallow copy)</r>
- 클래스 안에 포인터 멤버가 있을때 디폴트 복사 생성자가 <r>메모리 자체를 복사하지 않고 주소만 복사하는 현상</r>


## <r>깊은 복사(Deep copy)</r>
- 클래스 안에 포인터 멤버가 있을때 <r>메모리 주소를 복사하지 말고 메모리 자체 복사본을 만드는 기술</r>

```c++
#include <iostream>
#include <cstring>

class Person
{
    char* name;
    int   age;
public:
    Person(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name;}


    Person(const Person& p) : age(p.age)
    {
        // 포인터는 복사하지 말고, 새롭게 메모리 할당
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);        
    }
};


int main()
{
    Person p1("kim", 20);
    Person p2 = p1; 

}
```

## 깊은 복사의 단점
- 객체를 여러번 복사하면 <r>동일한 자원이 메모리에 여러번 놓이게 된다.</r>
- 자원의 크기가 큰 경우 메모리 낭비가 발생

## 참조 계수 (reference counting)
- <r>여러 객체가 하나의 자원을 공유</r>하게 한다.
- 단, 몇명의 객체가 자원을 사용하는지 <r>개수를 관리</r>한다.

```c++
class Person
{
    char* name;
    int   age;
    int*  ref;
public:
    Person(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        
        ref = new int(1);
        //*ref = 1;
    }
    
    
    ~Person() 
    {
        // 참조 계수 기반인 경우의 소멸자
        if ( --(*ref) == 0 )
        {
            delete[] name;
            delete ref;
        }
    }
    Person(const Person& p) 
                : name(p.name), age(p.age), ref(p.ref)
    {
        ++(*ref);
    }    
};
int main()
{
    Person p1("kim", 20);
    Person p2 = p1; 

}
```

## 참조 계수에서 좀더 생각해야할 점
- p1 객체가 자신의 이름을 변경하면 어떻게 될까?
- p2의 이름은 변경되면 안되므로 공유했던 자원은 분리되어야 한다.
- 멀티 스레드 환경에서는 동기화의 오버헤드가 추가된다.

