# module


```c++
////////// math.ixx

export module math;

export int add(int fir, int sec)
{
    return fir + sec;
}


////////// using_module.cpp

//#include <iostream>
//#include "math.h"
import std.core;
import math;

int main()
{
    int n = add(10, 20);

    std::cout << n << std::endl;
}
// cl.exe math.ixx /c /std:c++latest
// cl.exe using_module.cpp math.obj /std:c++latest
```


