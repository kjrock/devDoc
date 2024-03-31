<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 핵심1. 2가지 형태로 만들수 있다.
- 멤버 함수
- 멤버가 아닌 함수

## 핵심2. operator+ 함수 이름을 직접 사용해서 호출할수 있다.
|||
|--|--|
|멤버가 아닌 함수로 구현|operator+(p1, p2);<br>위 코드로 직접 호출 가능|
|멤버 함수로 구현|p1.operator+(p2);<br>위 코드로 직접 호출 가능|

```c++
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";

	auto ret1 = s1 + s2; 
//	auto ret2 = s1.operator+(s2); // error
	auto ret3 = operator+(s1,s2); 
}
```

## 연산자 재정의와 const member function
- 객체의 상태가 변경되지 않은 연산자는 const member function으로 해야 한다.

|||
|--|--|
|+|operator+(const Point& p2) <r>const</r> <br>operator+(<r>const</r> Point& p1, const Point& p2)|
|+=|operator+=(const Point& p2)<br>operator+=(Point& p1, const Point& p2)|

```c++
class Point
{
	int x{0};
	int y{0};
public:
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}

	// p1 이 상수 객체라도 "p1 + p2" 할수 있어야 한다. 상수 멤버 함수로 작성
	Point operator+(const Point& p) const
	{
		Point pt{p.x + x, p.y + y};
		return pt;
	}

	// p1 이 상수 객체라면 "p1 += p2" 는 할 수 없다. "비 상수" 멤버 함수로 작성.
	Point& operator+=(const Point& p)
	{	
		x += p.x;
		y += p.x;
		return *this;
	}
};
```

# 연산자 재정의 주의사항
## 1. 인자가 모두 primitive type인 경우 overloading할수 없다.
```c++
int operator+(int a, int b)  // error
{
	return a - b;
}

int ret = 3 + 2;
```

## 1. 인자의 개수를 변경할수 없다.
```c++
void operator+(Point p1, Point p2, Point p3) // error
{

}
```

## 3. default parameter를 사용할수 없다.
```c++
void operator+(Point p1, int n = 0) { // error

}
```

## 4. 새로운 연산자를 만들수 없다.
```c++
void operator+*(Point p1, Point p2) { // error

}
```

## 5. [], (), ->, = 연산자는 멤버 함수로만 만들수 있다.
```c++
void operator[](int idex) {  // error

}
```

## 6. 아래 연산자는 재정의 할수없다.
`.`  `.*`   `::`  `?:` <br>
`sizeof`   `typeid` <br>
`static_cast`  `dynamic_cast`  `reinterpret_cast`  `const_cast` <br>

## 7. 중요한 연산자
|||
|--|--|
|++|stl의 반복자 등을 만들때 사용|
|[]|`v[0] = 10;`의 표기법 지원|
|()|함수 객체(function object)|
|->, *|스마트 포인터(smart pointer)|
|=|객체의 복사|


## 8. 연산자 우선순위는 변경할수 없다.
## 9. `+`와 `=`를 모두 재정의해도, `+=`이 자동 지원되는 것은 아닌다.