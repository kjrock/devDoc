#include <print>

class Object
{
public:
	Object()          { std::println("1");}
	Object(int, int)  { std::println("2");}
	Object(std::initializer_list<int>) { std::println("3");}
};

int main()
{
	Object o1;			// 1
	Object o2(1, 2);	// 2
	Object o3({1,2});	// 3

	Object o4{1, 2};	// 3

//	Object o5(1, 2, 3); // error. Object(i, i, i) X
	Object o6{1, 2, 3}; // ok
	Object o7 = {1, 2, 3}; // ok
}