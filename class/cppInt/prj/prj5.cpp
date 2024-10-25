// 과제 5. STL vector와 유사한 클래스 만들기

// 아래 Point 에는 디폴트 생성자가 없습니다. 디폴트 생성자를 만들지 말고,
// 아래 상태에 과제를 진행해 주세요.

#include <cstring>
#include <iostream>
#include <initializer_list>

using namespace std;

class Point
{
public:
    Point(int a, int b) {}
};

// 아래 main 함수가 실행되도록 Vector를 구현해야 합니다.
template<typename T> class Vector
{
    T* buff;
    int sz;     // size
    int capa;   // capacity ( 메모리 사용량 )
public:
	Vector(int n, const T& other) : sz(n), capa(n)
    {  
        T* buff = static_cast<T*>(operator new(sizeof(T) * sz));
        for (int i=0; i<sz; ++i)
        {
            memcpy(&buff[i], &other, sizeof(T));
        }
    }
    // Vector(std::initializer_list<T> s)
    // {
    //     sz = s.size();
    //     capa = sz;
    //     T* buff = static_cast<T*>(operator new(sizeof(T) * sz));
    //     int index = 0;
    //     for(auto i : s)
    //     {
    //         buff[index] = i;
    //         ++index;
    //     }
    // }
    void resize(int n, const T& other=T(0,0))
    {  
        if (n <= sz)
        {
           for (int i=0; i<sz-n;++i)
            {
                buff[sz-i-1].~T();
            }

            sz = n;
        } 
        else
        {

            T* new_buff = static_cast<T*>(operator new(sizeof(T)*n));

            for (int i=0; i<sz; ++i)
            {
                memmove(&new_buff[i], &other, sizeof(T));
            }

            for (int i=0; i<n-sz; ++i)
            {
                memcpy(&new_buff[sz+i], &other, sizeof(T));
            }

            for (int i=0; i<sz;++i)
            {
                buff[i].~T();
            }

            delete[] buff;

            buff = new_buff;
            sz = n;
            capa = n;
        }
    }
    int size() { return sz;}
    int capacity() { return capa; }
};

int main()
{
    // 1. 아래 한줄이 실행되게 해주세요.
    //     Point 10개를 위한 버퍼가 만들어져야 하고,Point(1,1)로 초기화 되어야 합니다.
    Vector<Point> v(10, Point(1,1));

    // 2. 버퍼가 20개로 할당되고 기존 10개는 이동(복사)하고,
    //     새로운 10개는 Point(0,0)으로 초기화되게 하세요.
    v.resize(20, Point(0,0));

    // 3. 버퍼 크기를 다시 10개로 줄여 주세요. - 실제 메모리는 줄이지 말고, 객체만 파괴(소멸자 호출)해 주세요.
    v.resize(10);

    cout << v.size() << endl;       // 10
    cout << v.capacity() << endl;   // 20

    // 4. initializer_list 추가하기.
    // Vector<int> v2{ 1,2,3,4,5,6,7,8,9,10 };

    // 5. ranged for 지원하기
    // for (auto n : v2)
    //     cout << n << endl; // 1,2,3,4,5,6,7,8,9,10
}