#include <cstring>

class Person
{
	char* name;
	int   age;
public:
	Person(const char* s, int a) : age{a}
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	~Person() { delete[] name; }

	Person(const Person& p) : age{p.age}
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);		
	}	

	Person(Person&& p) noexcept
		: name{p.name}, age{p.age}
	{
		p.name = nullptr;	
		p.age = 0;
	}	
};

Person p{"john", 20};

Person foo()
{
	return p;
}

int main()
{
	Person p1{"john", 20};

	Person p2  = p1;
	Person ret = foo(); 
}