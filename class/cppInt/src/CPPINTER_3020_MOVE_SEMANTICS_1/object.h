// Object.h
#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

class Object
{
public:
	Object() = default;
	Object(const Object& obj)     { std::cout << "copy\n";}
	Object(Object&& obj) noexcept { std::cout << "move\n";}
};

#endif