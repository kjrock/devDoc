<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# foo 함수에 Rect 타입 변수 rc를 전달하는데,
- <r>foo 함수 안에서는 rc의 상태는 변경되면 안된다.</r>
  - call by value로 전달하면 된다.
  
# call by value
- 인자로 전달된 변수를 수정하지 않겠다는 약속
- 그런데, 구조체 같은 사용자 정의 타입은 인자로 사용하는 경우, <r>복사본에 대한 오버헤드</r>가 있다.

# const reference
- <r>복사본에 대한 오버헤드</r>없이 인자로 <r>전달된 변수를 수정하지 않겠다</r>는 약속
- C++에서 가장 널리 사용되는 인자 전달 방식

```c++
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

//void foo( Rect r )
void foo( const Rect& r )
{
	r.left = 100; // error
}

int main()
{
	Rect rc = {1, 1, 5, 5};
	foo(rc);
}
```

# 함수 인자를 받는 방법
## 1. 인자의 값을 변경하는 경우
- 포인터나 레퍼런스 모두 가능
- C++에서는 레퍼런스를 좀더 많이 사용

|||
|--|--|
|pointer| void swap(int* p1, int* p2)|
|reference|void swap(int& r1, int& r2)|

## 2. 인자의 값을 변경하지 않는 경우
- 인자의 타입에 따라 다름.

|||
|--|--|
|user define type|<r>const reference 사용</r><br> 일반적인 타입의 크기가 크다.<br>메모리 사용량 증가 및 복사 생성자 호출의 오버헤드를 줄이기 위해|
|primitive type|<r>call by value 사용</r><br>타입의 크기가 크지 않고, 생성자 개념이 없다.<br>reference를 사용하는 것보다 더 많은 컴파일러 최적화가 지원된다.|

```c++
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

// 다음중 좋은 코드는 ?
void f1(Rect r)        {}
void f2(const Rect& r) {} // 좋은 코드 

void f3(int n)        {} // 좋은 코드
void f4(const int& r) {}
```