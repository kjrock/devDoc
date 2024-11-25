// 2. 아래 코드는 reference counting을 사용하는 Label 클래스 입니다.
// main 함수가 실행될수 있도록, [] 연산자를 제공해 주세요.

#include <iostream>
#include <string.h>

class Label
{
    char* text;
    std::size_t size;
    int* ref;
public:
    Label(const char* s) : ref(new int(1))
    {
        size = strlen(s);
        text = new char[size + 1];
        // strcpy_s(text, size + 1, s);
        strncpy(text, s, size + 1);

        ref = new int(1);
    }
    Label(const Label& other) : text(other.text), size(other.size), ref(other.ref)
    {
        ++(*ref);
    }
    char& operator [](int idx) {
        char* text_old = text;
        text = new char[size + 1];
        strncpy(text, text_old, size + 1);
        ref = new int(1);
        return text[idx];
    }

    char operator [](int idx) const {
        return text[idx];
    }
    ~Label()
    {
        if (--(*ref) == 0 )
        {
            delete ref;
            delete text;
        }
    }
    void print() const { std::cout  << text << std::endl; }
};

int main()
{
    Label lb1("hello");
    Label lb2 = lb1;

    // 과제 : 아래처럼 동작하도록 [] 연산자를 재공해 보세요.
    char c = lb1[0];  // lb1, lb2 는 계속 자원을 공유해야 합니다.
    lb1[0] = 'A';     // lb1, lb2 의 자원을 분리 되어야 합니다.

    lb1.print();  // "Aello"
    lb2.print();  // "hello"
}