#include <iostream>
#include <thread>

void helloFunction() {
    std::cout << "Hello C++11 from a function." << std::endl; // 함수
}

class HelloFunctionObject {
public:
    void operator()() const {
        std::cout << "Hello C++11 from a function object." << std::endl; // 함수 객체
    }
};

int main() {

    std::cout << std::endl;

    // thread executing helloFunction
    std::thread t1(helloFunction); // 함수

    // thread executing helloFunctionObject
    HelloFunctionObject helloFunctionObject;
    std::thread t2(helloFunctionObject); // 함수 객체

    // thread executing lambda function
    std::thread t3([] {std::cout << "Hello C++11 from lambda function." << std::endl; }); // 람다 함수

    // ensure that t1, t2 and t3 have finished before main thread terminates
    t1.join();
    t2.join();
    t3.join();

    std::cout << std::endl;

};
