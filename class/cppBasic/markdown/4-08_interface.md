<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 개방-폐쇄 원칙 (OCP, Open-closed principle)
- 소프트웨어 개체(클래스, 모듈, 함수 등)는 <r>확장에 대해 열러있어야 하고, 수정에 대해서는 닫혀있어야 한다.</r>는 프로그램 원칙
- 새로운 요소가 추가되어도 기존 요소가 변경되지 않도록 설계해야 한다는 원칙

```c++
class Camera
{
public:
	void take() { std::println("take picture"); }
};

class HDCamera
{
public:
	void take() { std::println("take HD picture"); }
};

class People
{
public:
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ?
}
```

## 추상 클래스 vs 인터페이스
|||
|--|--|
|인터페이스|지켜야할 규칙만 있는 경우|
|추상클래스|지켜야할 규칙 + 다른 맴버도 있는 경우|

- java, c# 등 대부분의 객체지향 언어는 <r>abstract, interface</r> 라는 별도의 키워드 제공
- C++은 추상 클래스 문법만 존재

## 인터페이스를 만들때
- 결국 기반 클래스로 사용되므로 반드시 <r>가상 소멸자</r> 사용
- class 대신 struct를 사용하는 경우도 있다.
  - 모든 멤버를 public으로 할경우

```c++
// 규칙 : 모든 카메라는 ICamera 로 부터 파생 되어야 한다.
// 규칙 : 모든 카메라는 ICamera 인터페이스를 구현해야 한다.
//class ICamera
struct ICamera
{	
//public:
	virtual ~ICamera() {}

	virtual void take() = 0;	
};

class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { std::println("take picture"); }
};

class HDCamera : public ICamera
{
public:
	void take() { std::println("take HD picture"); }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::println("take UHD picture"); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

	UHDCamera uhc;
	p.use_camera(&uhc); // ok
}
```

## 강한 결합 (tightly coupling)
- 객체가 다른 객체와 강하게 결합되어 있는 경우
- 교체가 불가능하고 확장성 없는 경직된 디자인

## 약한 결합 (loosely coupling)
- 객체가 다른 객체와 약하게 결합되어 있는 경우 (interface를 통해서 통신)
- 교체가 가능하고 확장성있는 유연한 디자인


