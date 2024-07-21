// 2. 코루틴을 사용해서 홀수를 차례대로 무한히 반환하는 함수를 만들고, test 하는 main 함수도 작성해 주세요.

#include <iostream>
#include <coroutine>

class Generator
{
public:
    struct Promise
    {       
    private:
        int value;
    public:
        int getValue() const { return value; }

		Generator get_return_object()
		{
			return Generator{ std::coroutine_handle<Promise>::from_promise(*this) };
		}
		auto yield_value(int n) 
        {
            value = n;
            return std::suspend_always{}; 
        }
		auto initial_suspend() { return std::suspend_always{}; }
		auto return_void()     { return std::suspend_never{}; }
		auto final_suspend() noexcept  { return std::suspend_always{}; }
		void unhandled_exception() { std::exit(1); }
    };
    using promise_type = Promise;
    std::coroutine_handle<promise_type> coro;
    Generator( std::coroutine_handle<promise_type> c ) : coro(c) {}
   
    ~Generator() { if ( coro ) coro.destroy();}
};
Generator foo()
{   
   for(int n=1;; n+=2) {
    std::cout << "foo: return: " << n <<  std::endl;
    co_yield n;
   }
}
int main()
{
    Generator g = foo();

    std::cout << "\tmain1" << std::endl;
    for(int n=0; n<10; n++) {
        g.coro.resume();
        std::cout << "\tmain1, getValue(): " <<g.coro.promise().getValue() << std::endl;
    }
}