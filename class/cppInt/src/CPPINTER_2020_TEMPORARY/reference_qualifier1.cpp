#include <print>

class X
{
public:
	void f1()    { std::println("f1()");}
	void f2() &  { std::println("f2() &"); }
	void f2() && { std::println("f2() &&");}
	void f3() && { std::println("f3() &&");}
};
int main()
{
	X obj;

	obj.f1();
	X{}.f1();

	obj.f2(); // &
	X{}.f2(); // &&

//	obj.f3(); // error
	X{}.f3(); // ok
}