<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 함수가 객체를 값으로 반환하는 경우, 리턴용 임시객체(temporary)가 생성되어서 반환 된다.

## return용도로 생성된 임시객체(temporary)
- 함수를 호출하는 <r>문장의 끝에서 파괴</r>된다.
- 등호의 왼쪽에 놓을수 없다.(rvalue)

## temporary의 생성과 파괴
- 생성될때 복사 생성자가 호출되고
- 파괴될때 소멸자가 호출된다.
  

```c++
struct Point
{
	int x;
	int y;
};
Point pt = {1, 2};

Point f1()  // return by value
{
	return pt;
}
Point& f2() // return by reference
{
	return pt;
}
int main()
{
//	f1().x = 10; // 리턴용임시객체.x = 10
				 // error
	f2().x = 10; // pt.x = 10   ok.
}
```

## <r>갑 리턴</r>과 <r>참조 리턴</r>

|||
|--|--|
|return by value|리턴용 임시객체가 반환된다.|
|return by reference|리턴용 임시객체가 생성되지 않는다.|

## 주의 !!!
- 지역변수로 만들어진 객체는 절대 참조 반환하면 안된다.
