#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue 
{
    list<T> data;
public:
    void Push(T t) {
        data.push_back(t);
    }
    T Pop() {
        T t = data.front();
        data.pop_front();
        return t;
    }
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    cout << q.Pop() << endl; // 10
    cout << q.Pop() << endl; // 20
}