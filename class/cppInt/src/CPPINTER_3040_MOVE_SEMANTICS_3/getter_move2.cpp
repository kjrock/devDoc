#include "cmc.h"

using String = LOGString<COPY | MOVE>;

class Machine
{
	String data{"Machine1 Data"};
public:
	      String& get() & { return data; }
	const String& get() const & { return data; }
	
	String&& get() && { return std::move(data); }
//	const String&& get() const && { return std::move(data); }
};
int main()
{
	Machine mm;
	const Machine cm;

	mm.get() = "new data"; // ok
//	cm.get() = "new data"; // error

	String s1 = mm.get();  // ok
	String s2 = cm.get();  // ok

	using MM = Machine;
	using CM = const Machine;
	String s3 = MM{}.get();
	String s4 = CM{}.get();
}