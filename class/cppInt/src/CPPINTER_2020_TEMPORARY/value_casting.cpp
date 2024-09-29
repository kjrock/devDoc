#include <print>

struct Base { int value = 10; };

struct Derived : public Base 
{ 
	int value = 20; 
};

int main()
{
	Derived d;
	std::println("{}", d.value);	// 20

	std::println("{}", static_cast<Base>(d).value); // 10 
	std::println("{}", static_cast<Base&>(d).value);// 10

//	static_cast<Base>(d).value = 30;	// error
	static_cast<Base&>(d).value = 30;	// ok
}