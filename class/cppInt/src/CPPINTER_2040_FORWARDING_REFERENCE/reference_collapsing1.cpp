int main()
{
	int n = 1;

	int* p = &n;
	int& r = n;

	int* *pp = &p; // ok.    pointer   to pointer
	int& &rr = r;  // error. reference to reference
}

