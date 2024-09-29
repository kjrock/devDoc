#include "cmc.h"

using String = LOGString<COPY | MOVE>;

class Machine
{
	String data{"Machine1 Data"};
public:
	const String&  get() const & { return data; }
	
	String&&  get() && { return std::move(data); }
};

int main()
{
	Machine m;
	String s1 = m.get();

	String s2 = Machine{}.get();
}