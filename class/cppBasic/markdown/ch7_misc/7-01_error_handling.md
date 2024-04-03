<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 함수가 실행 중에 실패했으면
1. 함수 내에서 프로그램(프로세스)를 종료
   1) std::exit() 등의 함수 사용
2. 호출자에게 오류가 발생했음을 알린다.

## 호출자에게 함수가 실패했음을 알리는 방식
1) <r>약속된 함수 반환값(-1 등)으로 실패 전달</r>
   1) C 언어 및 대부분의 언어에서 사용
2) <r>예외(exception) 사용</r>
   1) 객체지향 언어의 대표적인 방법 (C++, java, C#, Python 등) 
3) <r>성공시 결과값 + 실패를 모두 담을 수 있는 타입을 반환하는 방식</r>
   1) 함수형 언어 및 일부 최신 언어가 사용

- 일반적으로는 오류의 심각성에 따라 위 방식들을 섞어서 사용


## 함수 반환 값으로 오류를 전달하는 방식
- 가장 널리 사용되던 방식(C언어)
- 오류를 나타내는 값을 약속한다.
- 오류 발생시 약속된 값 반환
- 함수 반환 타입이 void라는 것은 함수가 실패하지 않는다는 것을 의미

## 이 방식의 단점
1) <r>반환값과 오류가 완벽히 분리되지 않는다.</r>
   1) -1 이 실패를 의미 하는지? 연산의 결과인지?
2) <r>호출자가 발생된 오류를 무시할수 있다.</r>
   1) DB 백업이 실패했는데도
   2) 호출자가 무시하고 새로운 DB 작업을 한다면
   3) 더욱 큰 오류가 발생하게 된다.
   4) 심각한 오류는 호출자가 반드시 처리해야 한다.

```c++
#define ERROR -1

int db_backup() {
	// 서버에 접속해서 DB 를 백업하는 
	// 기능 수행하다가 오류가 발생했다면 ?	

	if ( 실패 )
		return ERROR;

	return 0;
}

void db_clear() {}

int main() {
	db_backup();
	db_clear();
}
```