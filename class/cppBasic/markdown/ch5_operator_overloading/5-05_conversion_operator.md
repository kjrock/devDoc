<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 객체의 요효성을 if문으로 조사할수 있을까?
- 객체가 bool로 변환 가능해야 한다.
- bool 뿐 아니라 if 조건에 놓일수 있는 타입으로 변활될수 있으면 된ㄴ다.

## 변환 연산자
- 객체가 다른 타입으로 변환이 필욯할때 호출되는 함수

|||
|--|--|
|int n = tcp;|tcp.operator int();|
|double d = tcp;|tcp.operator double();|
|Point p = tcp;|tcp.operator Point()|

## 변환 연산자 특징
- 객체가 다른 타입으로 변환되어야 할때 호출
- <r>반환타입을 표기하지 않는다.</r> (함수이름 자체에 반환 타입 포함)

```c++
class TcpConnect
{
	int state{0};
public:
	void connect() { } 

	operator bool() const 
	{
		return state != 0;
	}	
};

int main()
{
	TcpConnect tcp;
	tcp.connect();

	if ( tcp ) // tcp.operator bool()
	{
	}
}
```

## 변환 연산자의 위험성
- 객체의 변환은 <r>의도하지 않은 side effect</r>가 많다.
- 버그의 원인
- 되도록이면 <r>explicit를 붙이는 것이 좋다.</r>

## explicit 변환 연산자
- 직접 초기화와 명시적 변환만 허용
- 암시적 변환 허용 안됨.
- if 조건식 안에서는 사용 가능

```c++
class TcpConnect
{
	int state{0};
public:
	void connect() { } 	
	
	explicit operator bool() const { return state != 0; }	
};

void foo(bool b) {}

int main()
{
	TcpConnect tcp;

// explicit 가 아니면 아래 코드는 모두 허용됨.

//	bool b1 = tcp;	// error
	bool b2(tcp);	// ok
	bool b3 = static_cast<bool>(tcp); // ok
//	foo(tcp);	// error
//	tcp << 10;	// error
	if ( tcp ) {}	// ok	
}
```

## nullptr -> bool 변환
- explicit operator bool()과 동일하게 동작

```c++
void foo(bool b) {}

int main()
{
	if ( nullptr ) {}

//	bool b1 = nullptr;	// error
//	foo(nullptr);		// error
//	nullptr << 10;		// error

	bool b2(nullptr);	
	bool b3 = static_cast<bool>(nullptr);	
}
```