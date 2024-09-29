int main()
{
	int  n = 0;
	int& r = n;
	const int c = 0;
	const int& rc = c;

	auto& a1 = n;	// auto=int		a1=int&
	auto& a2 = r;	// auto=int		a2=int&
	auto& a3 = c;	// auto=const int	a3=const int&
	auto& a4 = rc;	// auto=const int	a4=const int&
}