#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex coutMutex;

class Worker {
public:
	Worker(std::string n) :name(n) {};

	void operator() () {
		for (int i = 1; i <= 3; ++i) {
			// begin work
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			// end work
			std::lock_guard<std::mutex> myLock(coutMutex);
			std::cout << name << ": " << "Work " << i << " done !!!" << std::endl;
		}

	}
private:
	std::string name;
};


int main() {

	std::cout << std::endl;

	std::cout << "Boss: Let's start working." << "\n\n";

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
mutex.cpp를 lock_guard를 이용하도록 변경!
적절한 위치에서 std::lock_guard 객체를 생성하기만 하면 뮤텍스가 자동으로 잠기고 풀린다.
*/