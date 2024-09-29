#include <utility>

struct ARRAY
{
	int x[3];
};

int main()
{
	int x1[3] = { 1,2,3 };
//	int x2[3] = x1;				// error
//	int x3[3] = std::move(x1);	// error

	ARRAY a1 = { 1, 2, 3 };
	ARRAY a2 = a1;				// ok
	ARRAY a3 = std::move(a1);	// ok

}