## 과제1. 숫자 야구 게임 만들기
아래 코드는 사용자가 생각한 숫자를 컴퓨터가 맞추는 게임입니다.
1. 컴퓨터가 정수 3개를 사용자에게 보여주고
2. 사용자로부터 strike, ball의 개수를 입력 받은후 3 strike 라면 종료됩니다.
3. 사용자로부터 입력된 결과를 분석해서 다시 3개의 정수를 구한 후 1부터 반복합니다.

참고로, 현재 컴퓨터가 사용하는 알고리즘은 무조건 중복되지 않는 난수 3개를 보여줍니다.

```c++
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

class BaseBallGame
{
    typedef tuple<int, int, int> INPUT;
    typedef tuple<int, int> RESULT;
    vector<pair<INPUT, RESULT> > v;
public:
    BaseBallGame() { srand((unsigned)time(0));}
    void run()
    {
        while(1)
        {
            //-----------------------
            // 이전의 결과가 담긴 vector v를 참고해서
            // 사용자가 생각한 숫자를 예층해 냅니다.
            // 현재 구현은 무조건 랜덤 입니다.
            int x = 0, y = 0, z = 0;
            do {
                x = rand() % 9 + 1;
                y = rand() % 9 + 1;
                z = rand() % 9 + 1;
            } while ( x == y || y == z || x == z);
            //------------------------------
            cout << "당신이 생각한 숫자는 " << x << ", " << y << ", " << z << " 입니까?" << endl;
            int strike = 0, ball = 0;
            cout << "strkie 갯수: ";
            cin >> strike;
            if (strke == 3)
            {
                cout << "성공 !"<< endl;
                break;
            }
            cout << "ball 개수: ";
            cin >> ball;
            //---------------------------------
            // 입력된 결과(strike, ball)을 기록해 두었다가
            // 다음수를 예측할때 사용합니다.
            v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
            dump()
        }
    }
    //필요한신 분을 위해 참고용으로 만든 함수입니다.
    void dump()
    {
        printf("-----------------------\n");
        printf("입력값 s b \n");
        for (auto& p : v) // p는 pair<INPUT, RESULT>입니다.
        {
            printf(" %d %d %d : %d %d\n",get<0>(p.first),get<1>(p.first),get<2>(p.first),get<0>(p.second),get<1>(p.second));
        }
        printf("-----------------------\n");
    }
};

int main(void)
{
    BaseBallGame bbg;
    bbg.run();
}

```

사용자가 생각한 숫자를 맞추는 알고리즘을 다양하게 변경할수 있습니다.
또는, 초급용/중급용/고급용 알고리즘을 교체하면서 사용할수도 있습니다. 
하지만, 위 코드는 하나의 함수안에서 모든 것을 처리하고 있기때문에
알고리즘을 교체하려면 BaseBallGame 클래스 자체를 수정해야 합니다.
과제는 다음과 같습니다.

## 과제 내용
위 코드에서 변하는 것에 해당하는 "이전 결과를 바탕으로 사용자가
생각한 숫자를 예측하는 부분"을 교체 가능한 설계로 변경해 보세요.
즉, BaseBallGame 클래스가 변하지 않고도 알고리즘을 교체할수 있도록 설계 구조를 변경하세요.
아래의 3가지 형태로 전부 작성해 주세요.
1. 변하는 부분을 가상함수로(template method)해서 구현해 보세요.
2. 변하는 것을 다른 클래스로 분리한 후, 인터페이스 기반으로 교체 가능한 설계(strategy)로 만들어 보세요.
3. 변한는 것을 다른 클래스로 부리한 후, 템플릿의 인자로 교체 가능한 설계(PolicyBase)로 만들어 보세요.

## 평가 규칙.
본 과정은 알고리즘 과정이 아니므로 알고리즘 자체는 평가 대상이 아닙니다. 프로그램의 구조만 평가합니다.
앞의 예문에서는 참고용으로 tuple, pair 등을 사용했는데, 잘 모르시는 분은 다른 방식으로 하셔도 전혀 문제 없습니다.




