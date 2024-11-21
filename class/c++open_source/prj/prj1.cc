// 1. 아래 코드는 unique_ptr의 삭제자를 변경해야 합니다.
// 람다 표현식을 사용해서 삭제자를 변경해 보세요.
// 단, C++17 환경에서 컴파일이 가능해야 합니다.


#include <memory>

int main()
{
    std::unique_ptr<int> up1(static_cast<int*>(malloc(sizeof(int)*20)));
}