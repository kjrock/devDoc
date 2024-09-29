#include <string>

struct Object
{
	std::string name;

	void set1(const std::string& n) { name = n; }	
	void set1(std::string&& n)      { name = std::move(n); }

	template<typename T>
	void set2(T&& n)
	{
		name = std::forward<T>(n);
	}	
};

int main()
{	
	Object obj;

//	obj.set1(65);	// error
	obj.set2(65);	// ok
}