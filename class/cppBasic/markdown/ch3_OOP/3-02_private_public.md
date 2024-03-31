<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 접근 지정자와 캡슐화
## 멤버 데이터를 외부에서 직접 접근하면
- 객체가 <r>잘못된 상태</r>가 될수 있다.
- 멤버 데이터는 <r>외부의 잘못된 사용으로부터 보호</r>하는 것이 안전하다.

## 접근 지정자

|||
|--|--|
|private|<r>맴버 함수에만 접근</r> 가능<br>멤버가 아닌 함수에서 접근시 에러|
|public|<r>모든 함수에서 접근</r> 가능|
|protected|멤버 함수와 파생 클래스 멤버 함수에서 접근 가능<br><r>상속</r> 강좌 참고|

```c++
#include <string>

//struct Person
class Person
{
//private:
	std::string name;
	int age;

public:
	void setAge(int value) {
		if ( value >= 1 && value < 150 )
			age = value;
	}
};

int main() {
	Person p;
//	p.age = -10; // error
	p.setAge(-10);
}
```

## 캡슐화 (Encapsulation)
- 멤버 데이터는 private 영역에 놓고 외부의 잘못된 사용으로부터 보호한다.
- 멈버 데이터의 변경은 잘 정의된 규칙을 가진 멤버 함수를 통해서만 변경 가능하게 한다.

## struct vs class

|||
|--|--|
|strcut|접근 지정자 생략시 디폴트가 <r>public</r>|
|class|접근 지정자 생략시 디폴트가 <r>private</r>|
