void f1(int a, int b) {}

int main()
{
	int n1 = 10;
	int n2 = n1; 	

	int arr1[3] = {1,2,3};
	int arr2[3] = arr1;		// error

	void f2(int, int) = f1;	// error

	int* p1 = arr1;	// ok
	void (*p2)(int, int) = f1;	// ok. 


	int (&r1)[3] = arr1;	// ok

	void (&r2)(int, int) = f1;	// ok
}