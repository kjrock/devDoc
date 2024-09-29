void f1(int a) {}

int main()
{
	int arr[3] = {1,2,3};

	auto  a1 = arr;
	auto& a2 = arr;

	auto  a3 = f1;
	auto& a4 = f1;
}