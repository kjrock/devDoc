template<typename T>
class Object
{
public:
	void f1(T&& arg) {}

	template<typename U>
	void f2(U&& arg) {}
};

int main()
{
	int n = 1;

	Object<int> obj1;
	obj1.f1(1);	// ok
//	obj1.f1(n); // error

	Object<int&> obj2;
//	obj2.f1(1);	// error
	obj2.f1(n);	// ok

	obj1.f2(1);
	obj1.f2(n);
	obj2.f2(1);
	obj2.f2(n);	
}