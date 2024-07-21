// 4. 아래 코드를 보고 main 함수의 주석처럼 동작하도록 작성해 보세요.

#include <iostream>
#include <iterator>
#include <type_traits>

template<typename Derived> class Base
{
    public:
    // Derived의 category 속성이 std::random_access_interator_tag 일 경우에만
    // foo 함수가 제공되도록 코드를 변경해 보세요.
    template<typename T>
    requires (typeid(typename Derived::category).hash_code() == typeid(std::random_access_iterator_tag).hash_code())
    void foo() {}
    void goo() {}
};
class A : public Base<A>
{
    public:
    using category = std::random_access_iterator_tag;
};
class B : public Base<B>
{
    public:
    using category = std::bidirectional_iterator_tag;
};

int main()
{
    // 과제의 핵심은 아래처럼 B는 foo함수가 제공되지 않아야 합니다.
    A a;
    B b;

    // std::cout << "A::category: " << typeid(A::category).hash_code() << std::endl;
    // std::cout << "std::random_access_iterator_tag: " << typeid(std::random_access_iterator_tag).hash_code() << std::endl;

    a.foo();  // ok
    a.goo();  // ok
//    b.foo();  // error 
    b.goo();  // ok
}



