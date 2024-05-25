#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue : public list<T>
{
public:
    void Push(T t) {
        list<T>::push_back(t);
    }
    T Pop() {
        T t = list<T>::front();
        list<T>::pop_front();
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