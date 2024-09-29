template<typename T1, typename T2>
auto add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	auto ret = add(1, 3.4);
}