<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 멤버 데이터 초기화
- 멤버 데이터를 초기화하는 3가지 방법

```c++
class Point {
    int x{0}; // 방법3, default member initializer, C++11
    int y{0};
public:
    Point(int a, int b) : x{a}, y{b} {  // 방법2, 멤버 초기화 리스트, C++98
        x = a;                          // 방법1, 지금까지 사용한 방법
        y = b;
    }
}
```

## 초기화 (initialization)
- 객체를 <r>생성하면서 초기값을 전달</r>하는 것
```c++
std::string name(s);
std::string name{s};
std::string name = s;
```

## 대입(assignment)
- 개체를 <r>생성한 후, 값을 전달</r>하는 것
```c++
std::string name;
name = s;
```

[예제]

```c++
#include <string>

class People1
{
	std::string name;
	int age;
public:
	People1(const std::string& s, int a) {
		name = s; // 대입
		age = a;
	}
};

class People2
{
	std::string name;
	int age;
public:
	People2(const std::string& s, int a) 
			: name{s}, age{a} // 초기화
	{}
};

int main()
{
	std::string s{"kim"};

	People1 p1(s, 20);
	People2 p2(s, 20);
}
```

## People1 타입의 객체 p1을 생성하면
- string 타입의 디폴트 생성자 호출
- 대입연산자 호출
- 성능 저하 발생
```c++
std::string name;
int age;
name = s;
age = a;
```


## People2 타입의 객체 p2을 생성하면
- 변수 생성과 할당이 동시에 함
- 성능 개선

```c++
std::string name{s};
int age = a;
```

## std::string 클래스의 정체는
- <r>basic_string</r> 이라는 클래스 템플릿

## 결론
- 생성자에서 멤버 데이터를 초기화할때는 <r>멤버 초기화 리스트(member initialize list)</r>를 사용하는 것이 좋다.