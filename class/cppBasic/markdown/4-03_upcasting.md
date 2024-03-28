<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>


```c++
class Animal 
{
    std::sting name;
    int age;
public:
    cry() {}
}
class Dog : public Animal
{
    int color;
public:
    void setColor(int c) { color = c;}
}

int main() {
    Dog dog;

    Dog* p1 = &dog;  // ok
    int* p2 = &dog;  // ng
    Animal* p3 = &dog;  // ok

    p3->cry();          // ok
    p3->setColor(5);    // ng
    static_cast<Dog*>(p3)->setColor(5);  // ok
}
```

## 1. 기반 클래스 포이터로 파생 클래스 객체를 가리킬수 있다. --> <r>upcasting</r>

## 2. 기반 클래스 포이터로는 기반 클래스의 멤버만 접근할수 있다.

## 3. 파생 클래스의 고유 멤버에 접근하려면 명시적으로 캐스팅(static_cast)해야 한다.


## upcasting 활용
- 동종(동일 기반 클래스부터 파생된 클래스)을 처리하는 함수
- 동종 보관하는 컨테이너

