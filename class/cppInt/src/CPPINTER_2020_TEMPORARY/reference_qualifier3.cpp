class X
{
public:
	void f1() &       { }
	void f2() const & { }	
};

int main()
{
	X obj;

	obj.f1(); // ok
//	X{}.f1(); // error

	obj.f2(); // ok  f2(obj)
	X{}.f2(); // ok  f2(x{})
}