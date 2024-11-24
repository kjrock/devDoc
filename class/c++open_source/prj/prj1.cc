// 1. 아래 코드는 unique_ptr의 삭제자를 변경해야 합니다.
// 람다 표현식을 사용해서 삭제자를 변경해 보세요.
// 단, C++17 환경에서 컴파일이 가능해야 합니다.


#include <memory>
#include <cstdlib>

int main()
{
    auto del = [](int* p) { std::free(p); };
    std::unique_ptr<int, decltype(del)> up1(static_cast<int*>(std::malloc(sizeof(int)*20)), del);
}