// 과제 2. perfect forwarding을 사용한 싱글톤 템플릿 만들기 입니다.
// 아래 코드는 싱글톤을 만들기 위해서 CRTP를 사용하고 있는 template 입니다.
#include <iostream>

template<typename Type> 
class Singleton
{
protected:
    Singleton() = default;
private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
template<typename ... A> 
    static Type& getInstance(A&& ... arg)
    {
        static Type instance(std::forward<A>(arg)...);
        return instance;
    }
};

class Mouse : public Singleton<Mouse>
{
public:
    Mouse() {}
};

// int main()
// {
//     Mouse& c = Mouse::getInstance();
// }

// 위 코드의 문제는 Singleton의 파생 클래스는 반드시 디폴트 생성자가 있어야 한다는 점이다.
// 위 코드를 수정해서 아래처럼 사용할수 있게 만들어 보세요.

class Cursor : public Singleton<Cursor>
{
public:
    Cursor(int x, int y) {}
};

int main()
{
    Cursor& c = Cursor::getInstance(1, 2);
}