#include <future>
#include <iostream>
#include <utility>


void doTheWork() {
    std::cout << "Processing shared data." << std::endl;
}

void waitingForWork(std::future<void>&& fut) {

    std::cout << "Worker: Waiting for work." << std::endl;
    fut.wait(); // 기다리기(set_value)
    doTheWork();
    std::cout << "Work done." << std::endl;

}

void setDataReady(std::promise<void>&& prom) {

    std::cout << "Sender: Data is ready." << std::endl;
    prom.set_value();

}

int main() {

    std::cout << std::endl;

    std::promise<void> sendReady;
    auto fut = sendReady.get_future(); // std::future

    std::thread t1(waitingForWork, std::move(fut));
    std::thread t2(setDataReady, std::move(sendReady));

    t1.join();
    t2.join();

    std::cout << std::endl;

}

/* 
스레드 동기화에 promise - future 조합을 사용할 수 있다.
prom.set_value()가 호출되면 미래 객체가 깨어나서 자신의 작업을 진행한다.

출력 결과
Worker: Waiting for work.
Sender: Data is ready.
Processing shared data.
Work done.

*/