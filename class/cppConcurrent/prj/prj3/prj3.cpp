// 공유 자원인 std::queue에 데이터를 넣고, 꺼내는 생산자/소비자 모델을 작성해 보세요.
// A. 생산자는 1개의 스레드입니다. 
//    Q에 데이터가 1000개 이하인 경우만 생산해야 합니다. 
//    1000개 이상인 경우는 대기해야 합니다.

// B. 소비자는 3개의 스레드입니다. 
//    Q에 데이터가 10개 이상인 경우만 소비해야 합니다.
//    10개보다 작은 경우 대기해야 합니다.

// C. mutex를 lock/unlock시 반드시 lock management clas 중 한개를 사용해 주세요.


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <queue>
using namespace std::literals;
  
std::mutex m;
std::condition_variable cv;
// bool data_ready = false;
std::queue<int> q;

void consumer()
{       
    while(1) 
    {
        std::unique_lock<std::mutex> ul(m);  
        cv.wait( ul, [] { return q.size() > 10;} );
        q.pop();
        std::cout << "consume size: " << q.size() << std::endl;
    }
}
void producer()
{     
    while (1) 
    {
        std::this_thread::sleep_for(100ms); 
        {
            std::lock_guard<std::mutex> lg(m);        
            if (q.size() < 1000) 
            {
                q.push(1);
                std::cout << "produce size: " << q.size() << std::endl;    
            }
        }

        if (q.size() > 10)
            cv.notify_all();
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    std::thread t3(consumer);
    std::thread t4(consumer);
    t1.join(); t2.join();
    t3.join(); t4.join();
}