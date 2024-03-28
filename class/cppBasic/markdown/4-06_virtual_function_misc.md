<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 가상함수를 만들때는 함수 앞에 virtual을 붙인다.

## 가상함수를 재정의 할때는 virtual 붙여도되고 붙이지 않아도 된다.
- 가독성을 위해서는 붙이는 것이 좋다.

## 가상함수 재정의시 함수 이름등에 오타가 있어도 에러가 발생하지 않는다.
- 컴파일러는 새로운 함수를 추가했다고 생각
- 가상함수 재정의시 <r>override</r>  를 붙이는 것이 안전하다.(C++11)

## 가상 소멸자

```c++
Base* p  = new Derived;
deleate p;
```
- Derived 객체를 생성했으므로 Derived 생성자 호출
- p가 가리키는 곳이 파괴되므로 소멸자를 호추해야 한다. 그런데, p의 타입이 Base*이므로 Base 소멸자만 호출됨

## 해결책
- 소멸자 호출시 포인터 타입이 아닌, p가 가리키는 메모리를 조사후 호출해야 한다.
- 기반 클래스의 소멸자를 가상함수로 한다.

```c++
class Shape
{
    int color;
public:
    virtual void draw() {}
};
class Rect : public Shape
{
    int width;
    int height;
public:
    virtual void draw() {}
};
void foo(Shape* p, Shape& r, Shape s) {
    p->draw();  // Rect draw
    r.draw();   // Rect draw
    s.draw();   // Shape draw
}
int main() {
    Rect r;
    foo(&r, r, r);
}
```

- 복사본 객체 생성 (Object Slicing)

