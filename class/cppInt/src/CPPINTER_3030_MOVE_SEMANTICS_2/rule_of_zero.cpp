#include <cstring>
#include <string>
#include <utility>

class Object
{
	std::string	name1;
	std::string name2;
	int   		data;
public:
	Object(const std::string& s1, const std::string& s2, int d)
	 	: name1{name1}, name2{s2}, data{d}
	{
	}


};

int main()
{
	Object o1{"name1", "name2", 20};

	Object o2 = o1;
	Object o3 = std::move(o1);

	o2 = o1;
	o3 = std::move(o2);
}
