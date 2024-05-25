#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> INPUT;
typedef tuple<int, int> RESULT;
typedef vector<pair<INPUT, RESULT> > DATA;

class IBaseBallGameAlgorithm 
{
public:
    virtual ~IBaseBallGameAlgorithm() {}
    virtual INPUT GetInputNum(DATA& data) = 0;
};

class BaseBallGameAlgorithmRandom : public IBaseBallGameAlgorithm
{
public:
    ~BaseBallGameAlgorithmRandom() {}
    INPUT GetInputNum(DATA& data) override {
        int x = 0, y = 0, z = 0;
        do {
            x = rand() % 9 + 1;
            y = rand() % 9 + 1;
            z = rand() % 9 + 1;
        } while ( x == y || y == z || x == z);

        cout << "input: " << x << ", " << y << ", " << z << endl;
        return INPUT(x,y,z);
    }
};

class BaseBallGame
{
    DATA v;
    IBaseBallGameAlgorithm* algo = nullptr;
public:
    BaseBallGame(IBaseBallGameAlgorithm* a) : algo(a) { srand((unsigned)time(0));}
    void run()
    {
        while(1)
        {
            INPUT input = algo->GetInputNum(v);
            //------------------------------
            cout << "are these your number? " << get<0>(input) << ", " << get<1>(input) << ", " << get<2>(input) << endl;
            int strike = 0, ball = 0;
            cout << "strkie count: ";
            cin >> strike;
            if (strike == 3)
            {
                cout << "success~~!"<< endl;
                break;
            }
            cout << "ball count: ";
            cin >> ball;
            //---------------------------------
            // 입력된 결과(strike, ball)을 기록해 두었다가
            // 다음수를 예측할때 사용합니다.
            v.push_back(make_pair(INPUT(get<0>(input), get<1>(input), get<2>(input)), RESULT(strike, ball)));
            dump();
        }
    }
    //필요한신 분을 위해 참고용으로 만든 함수입니다.
    void dump()
    {
        printf("-----------------------\n");
        printf("input value s b \n");
        for (auto& p : v) // p는 pair<INPUT, RESULT>입니다.
        {
            printf(" %d %d %d : %d %d\n",get<0>(p.first),get<1>(p.first),get<2>(p.first),get<0>(p.second),get<1>(p.second));
        }
        printf("-----------------------\n");
    }
};

int main(void)
{
    printf("start -----------------------\n");
    BaseBallGameAlgorithmRandom rnd;
    BaseBallGame bbg(&rnd);
    bbg.run();
    printf("end -----------------------\n");
}