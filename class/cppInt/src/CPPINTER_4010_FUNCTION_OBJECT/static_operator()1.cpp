struct Plus1
{
	int operator()(int a, int b) const 	{ return a + b;	}
};

struct Plus2
{
	static int operator()(int a, int b) { return a + b;	}
};

int main()
{
	Plus1 p1;
	Plus2 p2;

	auto n1 = p1(1, 2);
	auto n2 = p2(1, 2);
}