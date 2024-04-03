// 아래처럼 동작하는 utils::min 함수를 만드세요.
// 1. utils namespace 안에 만드세요.
// 2. template으로 작성해 주세요.
// 3. 인자는 const reference를 사용해 주세요.

#include <iostream>

namespace utils {
    auto min(const auto& a, const auto& b)
    {
        if (a < b)
            return a;

        return b;
    }
}

int main()
{
    std::cout  << utils::min(3, 4) << std::endl;     // 3
    std::cout  << utils::min(3.1, 2.3) << std::endl; // 2.3
}