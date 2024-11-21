// 3. 아래 코드가 정상 실행될수 있도록 drop_view를 완성해 주세요.
//    단, C++20에서 표준에 추가된 view_interface로부터 상속 받도록 만들어 주세요.

#include <vector>
#include <iostream>
#include <ranges>

int main()
{
    std::vector v = { 1,2,3,4,5,6,7,8,9,10};

    std::ranges::reverse_view rv(v);
    drop_view dv(rv, 3);

    for (auto e : dv)
        std::cout << e << ", ";

    // 실행 결과 : 7,6,5,4,3,2,1
}