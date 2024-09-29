#include <print>

class X
{
public:
	void foo() &        { std::println("foo &");} 
	void foo() &&       { std::println("foo &&");}
	void foo() const &  { std::println("foo const &");}
	void foo() const && { std::println("foo const &&");}
	void foo() volatile &  		{ std::println("foo volatile &");} 
	void foo() volatile && 		{ std::println("foo volatile &&");}
	void foo() const volatile &	{ std::println("foo const volatile &");} 
	void foo() const volatile &&{ std::println("foo const volatile &&");}

	virtual void goo() const volatile && noexcept final 
	{ 
		std::println("foo const volatile &&");
	}
};

int main()
{
	X obj;
	const X cobj;
	volatile X vobj;
	const volatile X cvobj;

	obj.foo();
	cobj.foo();
	vobj.foo();
	cvobj.foo();

	using CX = const X;
	using VX = volatile X;
	using CVX = const volatile X;

	X{}.foo();
	CX{}.foo();
	VX{}.foo();
	CVX{}.foo();
}