// 과제1. 람다 표현식과 지역변수 캡쳐

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // vector<int> x {1,2,3,4,5,6,7,8,9,10};
    int x[10]{1,2,3,4,5,6,7,8,9,10};
    int y[10];
    int v1=10;

    // x의 모든 요소에 v1를 더해서 y에 넣어 주세요.
    // 조건 1. x와 y가 배열이 아닌 vector인 경우도 코드 변경없이 실행되게 해주세요.
    // 조건 2. 람다 표현식을 사용해 주세요,.

    transform(begin(x), end(x), begin(y), [v1](int a){ return v1 + a; });

    for ( auto n : y)
        cout << n << endl; // 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 나와야 합니다. 

}