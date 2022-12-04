#include <iostream>
#include <thread>

void helloFunction() {
    std::cout << "Hello C++11 from a function." << std::endl;
}

class HelloFunctionObject {
public:
    void operator()() const {
        std::cout << "Hello C++11 from a function object." << std::endl;
    }
};

int main() {

    std::cout << std::endl;

    // thread executing helloFunction
    std::thread t1(helloFunction);  // 함수

    // thread executing helloFunctionObject
    HelloFunctionObject helloFunctionObject;
    std::thread t2(helloFunctionObject); // 함수 객체

    // thread executing lambda function
    std::thread t3([] {std::cout << "Hello C++11 from lambda function." << std::endl; }); // 람다 함수

    // ensure that t1, t2 and t3 have finished before main thread terminates
    t1.join(); // waits for the thread to finish its execution
    t2.detach(); // permits the thread to execute independently from the thread handle
    t3.join();

    std::cout << std::endl;

};
