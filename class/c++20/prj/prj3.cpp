// 3. Range 라이브러리를 사용해서 아래 코드를 완성해 보세요. 
// (drop_view과 filter_view를 사용해 주세요. 클래스 버전 또는 함수 버저. 어떤 버전을 사용해도 상관없습니다.)

#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // v에서 앞에서 3번째 이후의 요소 중
    // 짝수인 요소만 선택해서 각 요소를 2배로 한후에 출력해 주세요.

    auto rv = v | std::views::drop(3)
                | std::views::filter( [](int n) { return n % 2 ==0; } ) 
                | std::views::transform(  [](int a) { return a*2;});

    for(auto n : rv) std::cout << n << ", ";
}
