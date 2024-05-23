## 과제3. Queue 어답터 만들기
Queue가 필요합니다.

```c++
#include <iostream>
#include <list>
using namespace std;
int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    cout << s.Pop() << endl; // 10
    cout << s.Pop() << endl; // 20
}
```

Queue를 완전히 새로 만들필요 없이 STL의 list를 사용하면 간단하게 만들수 있습니다.
STL의 list를 사용해서 위 코드에서 사용할수 있는 Queue Adapter를 만들어 보세요.
1) 클래스 어답터로 만들어 보세요.
2) 객체 어답터로 만들어 보세요.