#include <cstring>
#include <string>
#include <utility>

class Object
{
	char* 		name1;
	std::string name2;
	int   		data;
public:
	Object(const char* s1, const std::string& s2, int d)
	 	: name2{s2}, data{d}
	{
		name1 = new char[strlen(s1) + 1];
		strcpy_s(name1, strlen(s1) + 1, s1);
	}
	~Object() { delete[] name1; }

	// move ctor - 잘못된 구현
	/*
	Object(Object&& other) 
		: name1{other.name1}, 
		  name2{other.name2}, 
		  data{other.data}
	{
		other.name1 = nullptr;	
	}	
	*/

	Object(Object&& other) 
		: name1{other.name1}, 
		  name2{std::move(other.name2)}, 
		  data{std::exchange(other.data, 0)}
	{
		other.name1 = nullptr;	
	}	



	// copy ctor
	Object(const Object& other) 
		: name2{other.name2}, data{other.data}
	{
		name1 = new char[strlen(other.name1) + 1];
		strcpy_s(name1, strlen(other.name1) + 1, other.name1);	
	}	
};

int main()
{
	Object o1{"name1", "name2", 20};

	Object o2 = o1;

	Object o3 = std::move(o1);
}
