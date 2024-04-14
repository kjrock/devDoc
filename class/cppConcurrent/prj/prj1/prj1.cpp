// 주어진 구간의 합을 구하는 프로그램을 작성해 주세요.
// 단, 구간의 합은 독립된 스레드로 구해야 합니다.스레드에서 결과를 얻기 위해서 promise와 future를 사용해주세요.
// 구간은 마음대로 하셔도 됩니다. (예, 1 ~ 1000)

#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void sum(std::promise<int>&& p, int a, int b)
{
	int s = 0;
    for(int i=a; i<=b; i++) {
      s += i;
    }
    std::cout << "s: " << s << std::endl;
	p.set_value(s);	
}
int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(sum, std::move(pm), 1, 100);
	int ret = ft.get();
	std::cout << ret << std::endl;
	t.join();
}