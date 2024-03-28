<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

```c++
class Base
{
public:
	virtual ~Base() {}
	virtual void f(int a = 10) { std::println("Base : {}", a);}	
};
class Derived : public Base 
{
public:
	void f(int a = 20) override { std::println("derived : {}", a);}	
};
int main()
{
	Derived d;
	Base* p = &d;

	p->f(); // derived : 10 
			// p->가상함수테이블[1]( 10 )
}
```

## 디폴트 파라미터
- 컴파일러가 <r>컴파일 시간</r>에 디폴트 값을 채운다.

## 가상함수
- 어느 함수를 호출할지를 <r>실행시간</r>에 결정

## 가상함수와 디폴트 파라미터
- <r>가상함수 override 시에는 절대 디폴트 값을 변경하면 안된다.</r>
