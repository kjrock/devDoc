<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

## 복사 금지
- 객체를 복사하지 못하게 하자는 의도
- 복사 생성자를 delete 한다.

```c++
class Person
{
    char* name;
    int   age;
public:
    Person(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name;}
    Person(const Person&) = delete;
};

int main()
{
    Person p1("kim", 20);
    Person p2 = p1; // 컴파일 에러가 나오게 하자
}
```

## 문자열이 필요하면 STL의 string 클래스를 사용하자
- 동적 메모리 할당을 할 필요가 없다.
- string이 내부적으로 자원를 관리해준다.
- int 변수처럼 사용하면 된다.


# 객체의 복사 방법 총정리
- 얕은 복사
- 깊은 복사
- 참조 계수
- delete 기법
- 문자열은 string으로