<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 복사 생성자 vs 대입 연산자

```c++
class Point
{
public:
	int x{0};
	int y{0};
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}	
};

int main()
{
	Point p1{1,2};
	Point p2;

	Point p3 = p1;  // 복사 생성자
	
	p2 = p1;        // 대입 연산자

	std::println("{}, {}", p2.x, p2.y);
}
```

|||
|--|--|
|복사 생성자|객체를 생성할때 초기화하는 것<br>Point p3(p1);<br>Point p3 = p1;|
|대입 연산자|객체를 생성 후에 값은 넣는 것<br>p2 = p1; // p2.operator=(p1)|

## 둘다, 사용자가 만들지 않으면 컴파일러가 기본 구현제공
- 모든 멤버를 복사 (bitwise copy)

```c++
Point& operator=(const Point& other) {
	x = other.x;
	y = other.y;

	return *this;
}
```

## 핵심1. 멤버 함수로만 만들수 있다.
## 핵심2. 자신을 참조로 반환해야 한다.
- 사용자 정의 타입도 int와 동일하게 동작하도록 하라.
`(p2 = p1) = p1;`
## 핵심3. 자신과의 대입을 조사한다.

## 컴파일러가 제공하는 버전을 사용하면 되는데, 왜 개발자가 구현 방법을 알아야 하나?
- Point 같은 일반적인 경우는 컴파일러 제공 버전을 사용해도 된다.
- 하지만, 클래스 안에 포인터 멤버 등이 있으면 주의해야 한다.

## 컴파일러가 대입 연산자를 만들지 못하게 하려면
- 함수 삭제(=delete) 문법 사용

## `n=10`의 결과가 다시 n이 나오는 것이 좋은가?
- `if (n = 5)`의 널리 알려진 버그 발생 가능성

## 대입 연산자의 결과가 `void`인 것이 좋지 않을까?
- C++은 자신을 참조로 변환하는 것이 원칙이지만,
- 요즘 나오는 많은 새로운 언어는 `void` 반환
- 