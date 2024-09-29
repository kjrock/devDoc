#include <algorithm>

class vector
{
	int* data;
	std::size_t size;
public:
	vector(std::size_t sz) 
		: size(sz), data(new int[sz]) 
	{
		std::uninitialized_fill_n(data, sz, 0);
	}

	~vector() { delete[] data;}

	int& operator[](int idx)       { return data[i];}


//	int operator[](int idx) const { return data[i];}

	const int& operator[](int idx) const { return data[i];}
};

int main()
{
	      vector v1{4};	
	const vector v2{4};
	
	int ret1 = v1[0]; // ok
	int ret2 = v2[0]; // ok

	v1[0] = 10;	// ok
	v2[0] = 10; // error

	int* p = &v2[0];
}
