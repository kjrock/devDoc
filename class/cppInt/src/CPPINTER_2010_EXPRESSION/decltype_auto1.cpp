int main()
{
	int arr[3] = {1, 2, 3};


	auto a1 = arr;		 // int* a1 = arr

	decltype(arr) d1;	 // int d1[3]

	

	auto a2 = arr[0];	 // int a2 = arr[0]
	
	decltype(arr[0]) d2; // int& d2;
						 // 초기값 문제로 error.
}