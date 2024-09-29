#include <print>

class Counter
{
	int cnt{0};
public:
//	Counter increment() 
	Counter& increment() 
	{
		++cnt;
		return *this;
	}
	int get() const {return cnt;}

	Counter() { std::println("Counter()");}

	Counter(const Counter& c) : cnt(c.cnt) 
	{ std::println("Counter(const Counter&)");}

	~Counter() {std::println("~Counter[{}]", cnt); }

};
int main()
{
	Counter c;
//	c.increment();
	c.increment().increment().increment();
	std::println("{}", c.get());
}