//auto add(auto a, auto b)

//decltype( a + b ) add(auto a, auto b)
auto add(auto a, auto b) -> decltype( a + b )
{
	if ( a == 0 ) return b;
	if ( b == 0 ) return a;
	return a + b;
}

int main()
{
	auto ret = add(1, 3.4);
}

