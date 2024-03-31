<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 핵심 개념
- RTTI (Run Time Type Information)
  - 실행시간에 타입의 정보를 얻을 때 사용하는 기술

## RTTI 기술을 사용하려면
- `<typeinfo>` 헤더를 포함한다.
- <r>typeid</r>> 연산자를 사용하면
- 타입의 정보를 담은 <r>type_info</r> 객체를 얻을 수 있다.
- type_info 객체의 멤버 함수 <r>name()</r> 사용  
- g++에서는 아래처럼 magling 전의 이름으로 표시
  - `[실행파일] | c++filt -t`

```c++
#include <iostream>
#include <typeinfo>

int main()
{
    int  n1 = 10;
    auto n2 = n1; // n2의 타입은? int 
    
    const std::type_info& t1 = typeid(n2);
    
    std::cout << t1.name() << std::endl;
}

```

## typeid
- 타입에 대한 정보를 얻을때 사용하는 연산자
- 다양한 형태로 사용할수 있다.

|||
|--|--|
|typeid(변수)|typeid( n1)|
|typeid(타입)|typeid( int)|
|typeid(표현식)|typeid( 3 + 3.4)|

- typeid 연산자의 결과로 <r>const std::type_info&</r>가 반환된다.

## std::type_info
- 타입의 정보를 담고 있는 클래스
- 사용자가 직접 객체를 만들수 없고, typeid() 연산자를 통해서만 얻을수 있다.

## g++로 생성된 실행파일의 경우 완전한 타입 이름을 출력하려면
`a.exe | c++filt -t`

## 타입을 출력하는 것이 아니라 조사하고 싶으면
- 2개의 type_info 객체를 == 연산자로 비교한다.
- typeid의 결과를 바로 비교해도 된다.

## 변수 n이 int 타입인지 조사하는 일반적인 코드
```c++
if( (typeid(n) == typeid(int)) {
	// n이 int type인 경우...
}
```
