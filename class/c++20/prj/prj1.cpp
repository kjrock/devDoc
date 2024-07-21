// 1. 람다표현식을 사용해서 swap 함수를 만드세요.
// 2개의 인자가 다른 타입이 전달될 경우 에러를 내기 위해서 C++20에서 추가된 템플릿 람다표현식을 사용해 주세요.
#include <iostream>

auto swap = []<typename T>(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
};

int main()
{
    int x = 1, y = 2;

    swap(x, y);

    std::cout << x << std::endl; // 2
    std::cout << y << std::endl; //1
}