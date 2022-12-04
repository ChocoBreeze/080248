#include <future>
#include <iostream>
#include <thread>
#include <utility>

void product(std::promise<int>&& intPromise, int a, int b) {
    intPromise.set_value(a * b);
}

struct Div {

    void operator() (std::promise<int>&& intPromise, int a, int b) const {
        intPromise.set_value(a / b);
    }

};

int main() {

    int a = 20;
    int b = 10;

    std::cout << std::endl;

    // define the promises
    std::promise<int> prodPromise;
    std::promise<int> divPromise;

    // get the futures
    std::future<int> prodResult = prodPromise.get_future();
    std::future<int> divResult = divPromise.get_future();

    // calculate the result in a separate thread
    std::thread prodThread(product, std::move(prodPromise), a, b);
    Div div;
    std::thread divThread(div, std::move(divPromise), a, b);

    // get the result
    std::cout << "20 * 10= " << prodResult.get() << std::endl;
    std::cout << "20 / 10= " << divResult.get() << std::endl;

    prodThread.join();

    divThread.join();

    std::cout << std::endl;

}

/*
다음은 약속 객체와 미래 객체의 조합을 활용하는 예이다.
이 예제는 약속 객체 prodPromise를 개별적인 스레드로 이동해서 계산을 수행한다.
이후 미래 객체 prodResult를 이용해서 그 결과를 얻는다(prodResult.get()).
*/