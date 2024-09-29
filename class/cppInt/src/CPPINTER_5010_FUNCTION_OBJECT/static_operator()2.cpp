int add(int a, int b) { return a + b; }

struct Plus
{
//	int operator()(int a, int b) const 	{ return a + b;	}

	static int operator()(int a, int b) { return a + b;	}

	using PF = int(*)(int, int);

	operator PF() const { return &Plus::operator();}

};

int main()
{
	Plus plus;

	int(*f1)(int, int) = add;
	int(*f2)(int, int) = plus; // ??
}