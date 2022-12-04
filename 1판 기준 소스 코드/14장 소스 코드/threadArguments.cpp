#include <chrono>
#include <iostream>
#include <thread>

class Sleeper {
public:
    Sleeper(int& i_) :i{ i_ } {};
    void operator() (int k) {
        for (unsigned int j = 0; j <= 5; ++j) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            i += k;
        }
        std::cout << std::this_thread::get_id(); // 정의되지 않은 행동
    }
private:
    int& i;
};


int main() {

    std::cout << std::endl;

    int valSleeper = 1000;
    std::thread t(Sleeper(valSleeper), 5);
    t.detach();
    std::cout << "valSleeper = " << valSleeper << std::endl; // 정의되지 않은 행동

    std::cout << std::endl;

}

/*
이 예제 코드에는 정의되지 않은 행동이 두 개나 있다.
첫 미정의 행동은 std::cout의 수명이 주 스레드의 수명에 묶여 있다는 점에서 비롯된다.
둘째 미정의 행동은 생성된 스레드가 자신의 매개변수 valSleeper를 참조로 전달받는다는 점에서 비롯된다.
생성된 스레드가 그것을 생성한 주 스레드보다 오래 살아남기 때문에, 주 스레드가 종료된 상황에서 std::cout과
valSleeper는 더 이상 유효하지 않은 객체이다.
*/