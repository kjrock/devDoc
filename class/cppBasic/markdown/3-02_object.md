<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 객체지향 프로그래밍 (Object Oriented Programming, OOP)

# 객체(Object) 란?
- 메모리에 존재하고, 이름으로 접근할수 있는 모든 것
- 일반적으로

|||
|--|--|
|int n;|변수(variable), primitive type instance|
|Rect r;|객체(Object), user define type instance|

```c++
int main() {
	int n = 10;
	Rect r = {0,0,5,5};
}
```

# Object memory layout
## Rect의 객체를 지역변수로 생성하면
- 스택에는 멈버 데이터만 객체당 한개씩 생성된다.
- 맴버 함수는
  - <r>객체의 개수에 상관없이 코드 메모리에 한 개</r>만 만들어진다 (멈버가 아닌 일반 함수와 동일)

```c++
struct Rect
{
	// stack 또는 heap에 생성
	int left;
	int top;
	int right;
	int bottom;

	// code memory에 생성
	int getArea() {	return (right - left) * (bottom - top);	}
	void draw()   {	std::cout << "Draw Rect" << std::endl;	}
};
```