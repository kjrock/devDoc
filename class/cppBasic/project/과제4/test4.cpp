// 아래 Buffer 클래스는 얕은 복사의 문제점이 있는 클래스 입니다.
// 복사 생성자를 제공해서 깊은 복사를 구현해 보세요.

#include <iostream>

template<typename T>
class Buffer
{
    T* ptr;
    std::size_t size;
public:
    Buffer(std::size_t sz) : size(sz)
    {
        ptr = new T[sz];
    }
    Buffer(const Buffer& b)
    {
        std::cout << "복사 생성자, size:" << b.get_size() << std::endl;
        ptr = new T[b.get_size()];
        size = b.get_size();
    }
    std::size_t get_size() const
    {
        return size;
    }
    ~Buffer() { delete[] ptr;}
};

int main()
{
    Buffer<int> b1(1024);
    Buffer<int> b2 = b1;  // 현재는 shallow copy 발생
                          // 문제가 없도록 복사 생성자를 만들어서
                          // deep copy로 구현해 주세요.
}