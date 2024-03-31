<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

```c++
#include <iostream>

class Shape
{
public:
    void Draw() { std::cout << "Shape::Draw" << std::endl; }
};

class Rect : public Shape
{
public:
    void Draw() { std::cout << "Rect::Draw" << std::endl; }
};

int main()
{
    Shape s; s.Draw(); // Shape::Draw
    Rect r;  r.Draw(); // Rect::Draw
    
    Shape* p = &r;     //
    p->Draw();         // Shape::Draw
}
```

## p->Draw()가 어떤 함수를 호출하는 것이 논리적으로 맞을까?
- 객체가 Rect이므로 Rect Draw

## 현재 코드에서 p->Draw()가 어떤 함수를 호출할까?
- Shape Draw 호출
- java, python 등의 대부분의 다른 객체지향 언어는 Rect Draw  호출

## 함수 바인딩 (Function Binding)
- <r>p->Draw()</r> 표현식을 <r>어느 함수와 연결</r>할지를 결정하는 과정
  

## static binding(early binding)
- 컴파일러가 <r>컴파일 시간에 함수 호출을 결정</r>
- 컴파일러는 p가 실제로 어느 객체를 가리키는지는 컴파일 시간에 알수 없다.
- 포인터 타입만을 가지고 함수 호출을 결정
- Shape Draw 호출
- 특징: 
  - 빠르다
  - 논리적이지 않다.
  - C++, C#의 non-virtual function

## dynamic binding (late binding)
-  컴파일 시간에는 p가 가리키는 곳을 조사하는 기계어 코드를 생성
-  <r>실행 시간에 p가 가리키는 곳을 조사후 실제 메모리에 있는 객체에 따라 함수 호출 결정</r>
-  Rect 객체가 있었다면 Rect Draw 호출
-  특징
   -  느리지만 논리적이다.
   -  java, python 등의 대부분의 객체지향 언어
   -  C++, C#의 virtual function
  
## virtual function vs non-virtual function
|||
|--|--|
|virtual function|함수 선언부에 virtual 붙은 멤버 함수<br><r>dynamic binding</r>|
|non-virtual function|함수 선언부에 virtual이 없는 멤버 함수<br><r>static binding</r>|

