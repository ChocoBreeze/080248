#include <iostream>
#include <thread>
#include <mutex>

std::once_flag onceFlag;

void do_once() {
    std::call_once(onceFlag, []() { std::cout << "Only once." << std::endl; });
}

int main() {

    std::cout << std::endl;

    std::thread t1(do_once);
    std::thread t2(do_once);
    std::thread t3(do_once);
    std::thread t4(do_once);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << std::endl;
}

/*
4개의 스레드 모두 함수 do_once를 실행하려 하지만, 실제로 실행하는 것은 네 스레드 중 하나 뿐이다.
따라서 함수는 정확히 한 번만 실행된다.

같은 std::once_flag로 서로 다른 여러 호출 가능 단위를 등록하고 그 중 하나만 실행되게 하는 것도 가능하다.
*/