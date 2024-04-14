// 1억개의 데이터를 가진 vector의 합을 구하는 프로그램을 작성해 주세요.
// A. 단일 스레드로 구하는 코드를 작성하세요.
// B. std::async를 사용해서 4개의 스레드로 구간을 나누어 계산하도록 작성해 보세요.

#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>

static const int NUM = 100000000; // 1억

long long sum(long long a, long long b)
{
	long long s = 0;
    for(long long i=a; i<=b; i++) {
      s += i;
    }
    std::cout << "s: " << s << std::endl;
	return s;
}

long long f1()
{
    return sum(1, NUM);
}

long long f2()
{
    auto future1= std::async(sum, 1, NUM / 4);
    auto future2= std::async(sum, NUM / 4 + 1, NUM / 2);
    auto future3= std::async(sum, NUM / 2 + 1, NUM * 3 / 4);
    auto future4= std::async(sum, NUM * 3 / 4 + 1, NUM);

    return future1.get() + future2.get() + future3.get() + future4.get();
}

void measure_execution_time( std::string name, long long(*f)()  )
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); 
    long long result = f();
    std::chrono::system_clock::time_point end  = std::chrono::system_clock::now(); 

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    
    std::cout << name << " : " << result << ", " << time_span.count() << " seconds." << std::endl;;
}

int main()
{
    measure_execution_time("f1", f1);
    measure_execution_time("f2", f2);
}