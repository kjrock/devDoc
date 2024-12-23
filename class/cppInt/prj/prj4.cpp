// 과제 4. 버퍼 이동하기

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class People
{
    string name;
    string addr;
    int    age;
public:
    People(string n, string add, int a) : name(n), addr(add), age(a) {}

	People(const People& other) : name{other.name}, addr{other.addr}, age{other.age}
	{
		cout << " Copy Ctor" << endl;
	}
	People(People&& other) noexcept : name{move(other.name)}, addr{move(other.addr)}, age{other.age}
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
    ~People() { std::cout << "~People()" << std::endl; }
    string gettInfoStr()
    {
        ostringstream oss;
        oss << name << ", " << addr << ", " << age;
        return oss.str();
    }
};

int main()
{
    // 3번 과제에서 만든 People를 사용하세요.

    // 1. People를 힙에 10개 생성해 보세요.
    //    People{"홍길동","서울",20} 으로 초기화 하세요.
    //    힌트) 메모리 할당과 생성자 호출을 분리 하세요.

    int n1 = 10;
	People* p1 = static_cast<People*>(operator new(sizeof(People) * n1));

	for (int i = 0; i < n1; i++)
	{
    	new(&p1[i]) People("홍길동","서울",20);
	}



    // 2. 위에서 만드는 배열(버퍼)를 20개 키워 보세요.
    //     A. 20개 버퍼를 새로 할당하고
    //     B. 기존에 버퍼의 내용을 새로운 버퍼에 옮기세요.
    //         move 생성자에 예외가 없다면 move 생성자로,
    //         예외가 있다면 복사 생성자로 옮기세요.
    //     C. 버퍼의 새로운 공간은 {"unknown", "unknown", 0} 으로 초기화 하세요.

    int n2 = 20;
	People* p2 = static_cast<People*>(operator new(sizeof(People) * n2)) ;

	for (int i = 0; i < n2; i++)
	{
        if (i < n1)
        {
            new(&p2[i]) People(std::move_if_noexcept( p1[i] ));
        }
        else 
        {
            new(&p2[i]) People("unknown","unknow",0);
        }
	}

    // 3. 새로운 버퍼의 내용을 출력하세요.
    for (int i = 0; i < n2; i++) 
    {
        cout << i << ", " << p2[i].gettInfoStr() << endl;
    }

    // 4. 버퍼을 줄이지는 말고 버퍼 끝에 있는 3개 객체를 파괴(명시적 소멸자 호출)해 보세요.
    for (int i = 0; i < 3; i++)
    {
        p2[n2 - i - 1].~People();
    }
}