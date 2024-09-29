#include <algorithm>
#include "cmc.h"

int main()
{
	for ( auto e : String{"ABCD"} )
	{
		std::println("{}", e);
	}

	for ( auto e : std::max(String{"AAA"}, 
						    String{"BBB"}) )
	{
		std::println("{}", e);
	}

}

