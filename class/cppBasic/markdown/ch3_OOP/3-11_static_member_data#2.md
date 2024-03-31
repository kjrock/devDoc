<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## static member data에 접근하는 2가지 방법
||||
|--|--|--|
|객체 이름으로 접근|c1.count|이 경우 count가 static 멤버인지 아닌지 구분이 안된다.|
|클래스 이름으로 접근|Car::count|이 방식을 <r>권장</r>|

- private 영역에 있는 경우, <r>static 멤버함수</r>로 접근

## 대부분의 다른 객체지향 언어는 클래스 이름으로만 접근할수 있다. : C#, java

## 클래스를 선언과 구현으로 분리할 경우
- static 멤버 변수의 외부 선언은 구현파일(.cpp)에 있어야 한다.

## 다음의 경우에는 외부 선언없이 클래스 내부에서 초기화 가능
- static const
- static constexpr
- inline variable (C++17)

```c++
struct Object
{
//	static int data1 = 0; // error
	static int data2;     // ok

	static const int data3 = 0;     // ok
	static constexpr int data4 = 0; // ok
		
	inline static int data5 = 0;
};
int Object::data2 = 0;
```