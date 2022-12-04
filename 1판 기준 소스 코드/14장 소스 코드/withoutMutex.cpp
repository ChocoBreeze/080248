#include <chrono>
#include <iostream>
#include <string>
#include <thread>

class Worker {
public:
    Worker(std::string n) :name(n) {};

    void operator() () {
        for (int i = 1; i <= 3; ++i) {
            // begin work
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            // end work
            std::cout << name << ": " << "Work " << i << " done !!!" << std::endl;
        }

    }
private:
    std::string name;
};


int main() {

    std::cout << std::endl;

    std::cout << "Boss: Let's start working.\n\n";

    std::thread herb = std::thread(Worker("Herb"));
    std::thread andrei = std::thread(Worker("  Andrei"));
    std::thread scott = std::thread(Worker("    Scott"));
    std::thread bjarne = std::thread(Worker("      Bjarne"));
    std::thread andrew = std::thread(Worker("        Andrew"));
    std::thread david = std::thread(Worker("          David"));

    herb.join();
    andrei.join();
    scott.join();
    bjarne.join();
    andrew.join();
    david.join();

    std::cout << "\n" << "Boss: Let's go home." << std::endl;

    std::cout << std::endl;

}

/*
여러 개의 스레드가 std::cout에 뭔가를 출력하게 하면 스레드들의 실행이 뒤섞이는 상황을 눈으로 관찰할 수 있다.
이 경우 출력 스트림 객체 std::cout이 공유 변수이다.

이 예제에서 std::cout에 대한 스레드들의 출력은 전혀 중재되지 않는다.

제대로 된 결과를 얻으려면 각 스레드가 std::cout을 독점적으로 사용하게 해야 한다.
*/