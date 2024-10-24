// 과제 3. move 지원 클래스 만들기

#include <string>
#include <iostream>
using namespace std;

class People
{
    string name;
    string addr;
    int    age;
public:
    People(string n, string add, int a) : name(n), addr(add), age(a) {}

    // 복사 생성자, 대입 연산자, move 생성자, move 대입 연산자를 만드세요.
    // 실행 여부를 확인하기 위해 logging을 해주세요.
	People(const People& other) : name{other.name}, addr{other.addr}, age{other.age}
	{
		cout << " Copy Ctor" << endl;
	}
	People(People&& other) : name{move(other.name)}, addr{move(other.addr)}, age{other.age}
	{
        other.age = 0;
		cout << " Move Ctor" << endl;
	}
	People& operator=(const People& other)
	{
        name = other.name;
        addr = other.addr;
        age = other.age;
		cout << " Copy =" << endl;
        return *this;
	}
	People& operator=(People&& other)
	{
         name = move(other.name);
         addr = move(other.addr);
         age = other.age;
         other.age = 0;

		cout << " Move =" << endl;
        return *this;
	}
};

int main()
{
    People p1{"홍길동", "서울", 20};
    People p2 = p1;
    People p3 = move(p1);
}

// 위 People 클래스에 복사 생성자, 대입 연산자, move 생성자, move 대입 연산자 를 만들어 보세요.