#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

struct CriticalData {
	std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b) {

	std::lock_guard<std::mutex>guard1(a.mut); // 1판에서는 그냥 a.mut.lock(); 
	std::cout << "get the first mutex" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	// 1ms라는 짧은 시간 구간도 교착 발생 확률을 크게 높인다. 
	// 두 스레드가 각자 상대 방이 잠근 뮤텍스가 풀리길 기다리기 때문에
	// 프로그램이 교착 상태에 빠진다.
	std::lock_guard<std::mutex>guard2(b.mut); // 1판에서는 그냥 b.mut.lock(); 
	std::cout << "get the second mutex" << std::endl;
	// do something with a and b
}

int main() {

	CriticalData c1;
	CriticalData c2;

	std::thread t1([&] {deadLock(c1, c2); });
	std::thread t2([&] {deadLock(c2, c1); });

	t1.join();
	t2.join();

}