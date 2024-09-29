#include <print>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::println("copy");}
	Object(Object&& obj)      { std::println("move");}
};

int main()
{
	Object o1, o2, o3;

	Object o4 = o1;
	Object o5 = o2;
	Object o6 = o2;
}