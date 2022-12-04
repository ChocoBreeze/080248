#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;

void doTheWork() {
    std::cout << "Processing shared data." << std::endl;
}

void waitingForWork() {

    std::cout << "Worker: Waiting for work." << std::endl;

    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, [] {return dataReady; }); // 자물쇠를 잠근 상태에서 통지를 기다린다.
    doTheWork();
    std::cout << "Work done." << std::endl;

}

void setDataReady() {

    std::lock_guard<std::mutex> lck(mutex_);
    dataReady = true;
    std::cout << "Sender: Data is ready." << std::endl;
    condVar.notify_one(); // 대기 중인 한 스레드에 통지한다.

}

int main() {

    std::cout << std::endl;

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();

    std::cout << std::endl;

}

// 송신자와 수신자에는 자물쇠가 필요하다.
// 송신자는 그냥 자물쇠를 한 번만 잠그고 풀면 되므로 std::lock_guard로 충분하다.
// 그러나 수신자는 뮤텍스를 여러 번 잠그고 풀어야 하는 경우가 많으므로 std::unique_lock이 필요하다.