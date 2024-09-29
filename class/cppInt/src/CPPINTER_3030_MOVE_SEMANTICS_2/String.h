// String.h
#include <print>
#include <string>

struct String : public std::string
{
	using std::string::basic_string;

	String(const String& s) 
		: std::string(static_cast<const std::string&>(s))
	{
		std::println("copy ctor");
	}

	String(String&& s) noexcept 
		: std::string(static_cast<std::string&&>(s))
	{
		std::println("move ctor");
	}

	String& operator=(const String& s)
	{
		std::string::operator=(static_cast<const std::string&>(s));
		std::println("copy =");
		return *this;
	}

	String& operator=(String&& s) noexcept
	{
		std::string::operator=(static_cast<std::string&&>(s));
		std::println("move =");
		return *this;
	}
};
