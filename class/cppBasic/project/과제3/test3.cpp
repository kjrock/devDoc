// STL의 사용법을 익히는 과제입니다. 아래 주석부분을 만들어 주세요.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

int main()
{
    std::vector<int> v;

    //1. 난수를 10개 구해서 v에 넣으세요.
    for (int count = 0; count < 10; count++){
     int r = rand() % 10;
     std::cout << r << std::endl;
     v.push_back(r);
    }
    std::cout << "------------------" << std::endl;
    
    int cmd = 0;

    while(1) {
        std::cout << "input cmd:" << std::endl;
        std::cin >> cmd;

        // 2. cmd가 1이면 v의 모든 내용을 화면에 출력해 주세요.
        if (cmd == 1) {
            std::cout << "1. print v" << std::endl;
            for(int i: v) {
                std::cout << i << std::endl;
            }
        }

        // 3. cmd가 2이면 v를 오름 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요.
        //    비교 정책으로 함수 객체를 사용해서 만들어 주세요.
        if (cmd == 2) {
            std::cout << "2. sort & print v" << std::endl;
            sort(v.begin(), v.end());
            for(int i: v) {
                std::cout << i << std::endl;
            }
        }

        // 4. cmd가 3이면 v를 내림 차순으로 정려한 후 v의 내용을 화면 출력해 주세요.
        //   비교 정책으로 람다 표현시을 사용해 주세요.
       if (cmd == 3) {
        std::cout << "3. desending sort & print v" << std::endl;
            sort(v.begin(), v.end(), [](int a, int b){ return a > b; });
            for(int i: v) {
                std::cout << i << std::endl;
            }
        }

        // 5. cmd가 4이면 또 다른 숫자를 하나 입력 받으세요.
        //    해당 숫자가 vector에 있으면 제거한 후 vector를 다시 출력해 주세요.
       if (cmd == 4) {
            std::cout << "4. remove num & print v" << std::endl;
            std::cout << "input num to remove" << std::endl;
            int num;
            std::cin >> num;
            v.erase(remove(v.begin(), v.end(), num), v.end());
            for(int i: v) {
                std::cout << i << std::endl;
            }
        }

        // 6. cmd가 5이면 또 다른 숫자를 하나 입력 받으세요.
        //    해당 숫자를 찾아서 0으로 변경한후 vector를 다시 출력해 주세요.
       if (cmd == 5) {
            std::cout << "5. reset num & print v" << std::endl;
            std::cout << "input num to reset" << std::endl;
            int num;
            std::cin >> num;
            replace(v.begin(), v.end(), num, 0);
            for(int i: v) {
                std::cout << i << std::endl;
            }
        }

        // 7. cmd가 6이면 v의 size를 20개로 늘린후 v의 내용을 출력해 주세요.
       if (cmd == 6) {
            std::cout << "6. resize 20 & print v" << std::endl;
            v.resize(20);
            for(int i: v) {
                std::cout << i << std::endl;
            }
        }

       if (cmd == 9) {
            break;
        }
    }

    return 0;
}