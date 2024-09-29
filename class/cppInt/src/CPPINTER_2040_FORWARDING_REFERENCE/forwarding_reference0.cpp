#include <type_traits>

template<typename T>
constexpr std::remove_reference_t<T>&& 
move( T&& obj ) noexcept
{
	return static_cast<std::remove_reference_t<T>&&>(obj);
}

int main()
{
	
}



