#include "Object.h"

Object global;

Object f1() { return global; }

int main()
{
	Object ret = f1(); 
}
