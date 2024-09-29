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

	Object(Object&& other) noexcept 
		: name1{other.name1}, 
		  name2{std::move(other.name2)}, 
		  data{std::exchange(other.data, 0)}
	{
		other.name1 = nullptr;	
	}	

	Object(const Object& other) 
		: name2{other.name2}, data{other.data}
	{
		name1 = new char[strlen(other.name1) + 1];
		strcpy_s(name1, strlen(other.name1) + 1, other.name1);	
	}	

	Object& operator=(const Object& other)
	{
		if ( &other == this )
			return *this;

		data  = other.data;
		name2 = other.name2;

		delete[] name1;

		name1 = new char[strlen(other.name1) + 1];
		strcpy_s(name1, strlen(other.name1) + 1, other.name1);	

		return *this;
	}

	Object& operator=(Object&& other) noexcept
	{
		if ( &other == this )
			return *this;

		data  = std::exchange(other.data, 0);
		name2 = std::move(other.name2);

		delete[] name1;

		name1 = other.name1;	
		other.name1 = nullptr;

		return *this;
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
