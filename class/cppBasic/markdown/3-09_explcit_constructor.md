<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 인자가 한개인 생성자가 있는 타입의 객체 생성 방법

||||
|--|--|--|
|Vector v1(1);|Direct Initilization<br>(직접 초기화)|C++98|
|Vector v2{1};|상동|C++11|
|Vector v3 = 10;|Copy Initilization<br>(복사 초기화)|C++98|
|Vector v4 = {10};|상동|C++11|

## 인자가 한개인 생성자는 변환의 용도로 사용될수 있다.
- <r>변환 생성자(conversion constructor)</r>

```c++
class Vector
{
public:
	Vector(int size){}
};

int main()
{
	// C++98
	Vector v1(10);  
	Vector v2 = 10; 

	// C++11
	Vector v3{10};  
	Vector v4 = {10}; 

	v1 = 20; // v1 = Vector(20)
}
```

[explcit 필요한 경우]
```c++
class Vector
{
public:
	explicit Vector(int size){}
};
void foo(Vector v)
{
}
int main()
{
	Vector v1(10);   // ok
	Vector v2 = 10;  // error
	Vector v3{10};   // ok
	Vector v4 = {10};// error 

	v1 = 20; 	// error

	foo(v1); // ok
	foo(10); // error
}
```

## explicit 생성자
- <r>Direct Initializetion만 가능</r>하고, Copy Initialization은 사용할수 없다.
- <r>암시적 변환의 용도로 사용될수 없다.</r>
- 명시적 변환은 사용 가능


## STL과 explicit 생성자
- 생성자가 explicit인 것도 있고, 아닌 것도 있다.

||
|--|
|string(const char* s);  // explicit 아님|
|vector(std::size_t sz); // explicit |

```c++
#include <vector>
#include <string>

void f1(std::string s)     {}
void f2(std::vector<int> v){}

int main()
{
	std::string s1("hello");
	std::string s2 = "hello"; // ok

	std::vector<int> v1(10);
	std::vector<int> v2 = 10; // error

	f1("hello"); // ok. string s = "hello"
	f2(10);      // error. vector<int> v = 10

	std::vector<int> v3 = 10;   // error
	std::vector<int> v4 = {10}; // ok, vector(std::initializer_list)
}
```

## vector 사용시 ()와 {} 
|||
|--|--|
|vector<int> v(10);| 크기가 10인 vector<br>explicit vector(std::size_t)|
|vector<int> v{10};| 크기가 1인(초기값 10)인 vector<br>vector(std::initializer_list)<br>explicit 생성자 아님|

## 인자의 개수가 없거나 여러개인 경우도 explicit를 붙일수 있다.

## explicit(bool)
- C++20에서 추가된 문법
- 주로, <r>클래스 템플릿 만들때 템플릿 인자에 따라서 explicit 여부를 결정</r>하기 위해 사용

```c++
#include <type_traits>

class Object
{
public:
//	explicit(false) Object(int a) {} 

	template<typename T>
	explicit( std::is_integral_v<T> ) Object( T arg ) {}
};

int main()
{
	Object o1(10);
//	Object o2 = 10;
	Object o2 = 3.4;
}
```