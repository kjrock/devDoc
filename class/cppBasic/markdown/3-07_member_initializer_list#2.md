<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 반드시 member initializer list를 사용해야 하는 경우,
- 멤버 데이터로 <r>상수나 참조가 있는 경우</r>
- <r>디폴트 생성자가 없는 타입이 멤버로 있는 경우.</r>

## 상수와 참조 변수는 반드시 초기화되어야 한다.
## 생성자 블록 안에서 대입한 경우,
```c++
const int c;  // error, 상수와 참조 변수는 반드시 초기화 되어야 한다.
int& r;       // error
c = n;        // error,  상수는 대입될수 없다.
r = x;
```

## 멤버 초기화 리스트를 사용하는 경우,
```c++
const int c = n;  // ok
int& r = x;       // ok
```

[사용 예]
```c++
class Object
{
	const int c;
	int& r;
public:
	Object( int n, int& x) : c{n}, r{x}
	{
//		c = n;
//		r = x;
	}
};

int main()
{
	int num = 10;

	Object obj(10, num);
}
```


## 디폴트 생성자 없는 타입이 멤버로 있는 경우

```c++
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x{a}, y{b}
	{
	}
};

class Rect
{
	Point leftTop;
	Point rightBottom;
public:
	Rect(int x1, int y1, int x2, int y2)
		: leftTop{x1, y1}, rightBottom(x2, y2) // ok
	{
	//	leftTop(x1, y1);                       // error
	}
};

int main()
{
	Rect r(1,1,10,10);
}
```

## 멤버 초기화 리스트 주의 사항
```c++
class Point
{
public:
	int x;
	int y;

	Point() : y{10}, x{y}
	{
	}
};
```

### 멤버 초기화 리스트의 실행 순서는
- 초기화 코드가 놓인 순서가 아니라
- <r>멤버 데이터가 선언된 순서대로 초기화</r> 된다.
```c++
int x = y;  // 미정의 동작 발생
int y = 10;
```

## 멤버 초기화 리스트의 코드를 작성할때는
- <r>멤버 데이터가 선언된 순서대로 초기화 코드를 작성하는 것이 좋다.</r>

## 선언과 구현 파일로 나우어 클래스를 작성할 때
- 멤버 초기화 리스트는 구현 파일에 작성

## 함수(생성자)의 인자 이름이 멤버 데이터의 이름과 동일한 경우
- 생성자 블록 안에서는 멤버에 접근하려면 `this->멤버이름`을 사용해야 한다.
- 멤버 초기화 리스트 코드에서는 this가 필요 없다.



