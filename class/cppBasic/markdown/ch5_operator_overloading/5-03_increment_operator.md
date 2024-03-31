<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## Point 객체를 ++ 한다는 것이 이론적으로 맞지 않을수 있지만,
- 문법 학습을 위한 예제
- ++ 연산시 x, y 모두 1 증가하는 것으로 구현
- 감소 연산자(--) 구현 방법은 동일

## 증가 / 감소 연산자 재정의가 사용되는 예
- C++ 표준 라이브러리인 STL의 반복자

## 핵심1. 전위형과 후위형을 구별해야 한다.
- 후위형을 만들때는 함수인자로 int타입을 한개 가져야 한다.<br>
  (사용되지는 않지만 전위형과 구별하기 위해서)


```c++
class Point
{
public:
	int x{0};
	int y{0};
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}	

	// 전위형
	Point operator++()
	{
		std::println("prefix ++");
		++x; ++y;	
		return *this;
	}

	// 후위형 
	Point operator++(int)
	{
		std::println("postfix ++");

		Point temp = *this;
		++x; ++y;	
		return temp;
	}
};

int main()
{
	Point p{1,1};
	Point temp1 = ++p;	// p.operator++()
	Point temp2 = p++;	// p.operator++(int)
	
}
```

## 핵심2. 전위형은 ++++p 표현식이 가능해야 한다.
- <r>자기 자신을 참조로 반환해야 한다.</r>
- 값을 반환하면 임시객체가 생성된다.

```c++
class Point
{
public:
	int x{0};
	int y{0};
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}	

	Point& operator++()
	{
		++x; ++y;	
		return *this;
	}
	Point operator++(int)
	{
		Point temp = *this;
		++x; ++y;	
		return temp;
	}
};
int main()
{
	Point p{1,1};

	++++p; // ++(++p) (p.operator++()).operator++()

	std::println("{}, {}", p.x, p.y);
}
```

## 핵심3. 후위형은 전위형을 사용해서 구현
- 정책을 관리하는 코드는 한곳에 있는 것이 좋다.

```c++
class Point
{
public:
	int x{0};
	int y{0};
	Point() = default;
	Point(int x, int y) : x{x}, y{y} {}	

	Point& operator++()
	{
		++x; ++y;	
		return *this;
	}
	Point operator++(int)
	{
		Point temp = *this;
		//++x; ++y;	
		++(*this); // this->operator++()
		return temp;
	}
};
```

## 핵심4. 전위형이 후위형보다 빠르다.
- 반환값을 사용하지 않고 단순히 증가만 한다면 전위형을 사용하는 것이 좋다.
- 그런데, 요즘 컴파일러는 코드의 문맥을 파악해서 동일한 기계어 코드 생성(최적화~)

