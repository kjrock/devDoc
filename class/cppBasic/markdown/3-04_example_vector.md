<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# 동적 배열 만들기
## 배열의 단점
- 크기를 변경할수 없다.

## 크기를 변경하려면
- 처음에 필요한 만큼의 메모리를 동작 할당.

## 동적 배열 (vector)
- 크기 변경이 가능한 배열
- 프로그램에서 자주 사용된다.
- C 언어는 재사용 가능하게 설계하는 것이 쉽지 않다.

## 객체지향 프로그래밍 (Object Oriented Programming)
- 타입을 먼저 만들자.
- <r>vector</r> 타입을 설계해 보자

[resize 구현]
```c++
#include <iostream>

class vector
{
	int* buff;
	int  size;
public:
	vector(int sz) 
	{
		size = sz;
		buff = new int[size];
	}
	~vector() {	delete[] buff;	}

	void resize(int newsize) {
		if ( newsize > size ) {
			int* temp = new int[newsize];
			memcpy(temp, buff,sizeof(int) * size);
			delete[] buff;
			buff = temp;
			size = newsize;
		}
	}
};

int main()
{
	vector v(5);
	v.resize(10);
	v.resize(20);
}
```
[setAt / getAt 구현]
```c++
#include <iostream>

class vector
{
	int* buff;
	int  size;
public:
	vector(int sz) {
		size = sz;
		buff = new int[size];
	}
	~vector() {	delete[] buff;	}

	void resize(int newsize) {
		if ( newsize > size )
		{
			int* temp = new int[newsize];
			memcpy(temp, buff,sizeof(int) * size);
			delete[] buff;
			buff = temp;
			size = newsize;
		}
	}
	void setAt(int idx, int value) {
		buff[idx] = value;
	}
	int getAt(int idx) {
		return buff[idx];
	}
};

int main()
{
	vector v(5);
	v.setAt(0, 55);
	v.resize(10);
	std::cout << v.getAt(0) << std::endl; // 55
}
```

[템플릿 구현]
```c++
#include <iostream>

template<class T> 
class vector
{
	T* buff;
	int  size;
public:
	vector(int sz) {
		size = sz;
		buff = new T[size];
	}
	~vector() {	delete[] buff;	}

	void resize(int newsize) {
		if ( newsize > size )
		{
			T* temp = new T[newsize];
			memcpy(temp, buff,sizeof(T) * size);
			delete[] buff;
			buff = temp;
			size = newsize;
		}
	}
	void setAt(int idx, const T& value)	{
		buff[idx] = value;
	}
	T getAt(int idx) {
		return buff[idx];
	}
};

int main()
{
	vector<double> v(5);
	v.setAt(0, 3.4);
	std::cout << v.getAt(0) << std::endl; // 3.4

}
```

## STL
- C++ 언어의 표준 라이브러리
- 대부분 템플릿으로 되어 있다.
- Standard Template Library

## std::vector
- 크기 변경이 가능한 동적 배열
- 사용법은 배열과 거의 동일하다.
- [] 연산자로 요소에 접근 가능


