#include <iostream>
#include "..\print.h"

int main()
{
    int n = 10;
    double d = 3.4;

    std::cout << "n = " << n << ", d = " << d << std::endl;

    std::println("n = {}, d = {}", n, d);
    std::println("{0}, {1}, {0}", n, d);

    std::print("hello ");  // 개행 안함
    std::println("hello ");  // 개행
}