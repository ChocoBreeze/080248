#include <utility>
#include <future>
#include <iostream>
#include <thread>
#include <deque>

class SumUp {
public:
    int operator()(int beg, int end) { // [beg, end) 까지의 합
        long long int sum{ 0 };
        for (int i = beg; i < end; ++i) sum += i;
        return sum;
    }
};

int main() {

    std::cout << std::endl;

    SumUp sumUp1;
    SumUp sumUp2;
    SumUp sumUp3;
    SumUp sumUp4;

    // define the tasks 
    // 1. 실행할 일감을 감싼 task 만들기 - std::packaged_task<int(int, int)> sumTask([](int a, int b) {return a + b; });
    std::packaged_task<int(int, int)> sumTask1(sumUp1);
    std::packaged_task<int(int, int)> sumTask2(sumUp2);
    std::packaged_task<int(int, int)> sumTask3(sumUp3);
    std::packaged_task<int(int, int)> sumTask4(sumUp4);

    // get the futures
    // 2. 미래 객체 생성 - std::future<int> sumResult = sumTask.get_future();
    std::future<int> sumResult1 = sumTask1.get_future();
    std::future<int> sumResult2 = sumTask2.get_future();
    std::future<int> sumResult3 = sumTask3.get_future();
    std::future<int> sumResult4 = sumTask4.get_future();

    // push the tasks on the container
    
    std::deque< std::packaged_task<int(int, int)> > allTasks;
    allTasks.push_back(std::move(sumTask1));
    allTasks.push_back(std::move(sumTask2));
    allTasks.push_back(std::move(sumTask3));
    allTasks.push_back(std::move(sumTask4));

    int begin{ 1 };
    int increment{ 2500 };
    int end = begin + increment;

    // execute each task in a separate thread
    // 3. task 실행 - sumTask(2000, 11);
    while (!allTasks.empty()) {
        std::packaged_task<int(int, int)> myTask = std::move(allTasks.front());
        allTasks.pop_front();
        std::thread sumThread(std::move(myTask), begin, end);
        begin = end;
        end += increment;
        sumThread.detach();
    }

    // get the results
    // 4. 결과 조회 - sumResult.get();
    auto sum = sumResult1.get() + sumResult2.get() + sumResult3.get() + sumResult4.get();

    std::cout << "sum of 0 .. 10000 = " << sum << std::endl;

    std::cout << std::endl;

}
/*
이 예제는 task(std::packaged_task 인스턴스; 앞에서 말한 약속 객체와 같은 역할을 함)들을 
대기열(std::deque) allTasks로 이동하고, while 루프로 과제들을 훑으면서 각 task를 개별적인 스레드로 실행한다.
각 task는 배경에서 (sumThread.detach()) 덧셈을 수행한다.
최종 결과는 0에서 10000까지의 합인 50005000이다.
*/