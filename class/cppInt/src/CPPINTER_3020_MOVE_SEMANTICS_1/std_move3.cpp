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
	const Object co;
	Object obj = std::move(co);
}