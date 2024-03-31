<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 정적 멤버 (static member)
- C++ 뿐만 아니라 대부분의 객체지향 언어가 지원하는 문법
```c++
class Car 
{
	int speed;       // member data (field)
	static int cnt;  // static member data(static field)
pulic:
	void Go() {}     // member function (method)
	void Stop() {}
	static int GetCount() { return cnt;} // static member function (static method)
}
int Car::cnt = 0;
```

## static member data (정적 멤버 데이터)
- 멤버 데이터 앞에 <r>static</r>을 붙이는 문법
- <r>반드시 클래스 외부에서 선언(정의) 되어야 한다.</r>

## static member data 특징
- 프로그램이 처음 시작될때(객체를 생성하지 않아도) 메모리에 놓이게 된다.
- 객체 생성시, <r>static member data는 객체의 메모리에는 포함되지 않는다.</r>
- 결국, 모든 Car 객체가 <r>Car::count를 공유</r>하게 된다.
- static 멤버 데이터는 <r>클래식이름::static멤버이름</r>으로 접근

|||
|--|--|
|int speed|객체당 한개씩 생성<br>instance field(member data)|
|static int count|클래스당 한개(동일 타입의 모든 객체 공유)<br>class field(member data)<br>static field(member data)|