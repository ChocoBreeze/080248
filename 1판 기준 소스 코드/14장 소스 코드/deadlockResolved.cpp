#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

struct CriticalData {
	std::mutex mut;
};

void deadLockResolved(CriticalData& a, CriticalData& b) {
	std::unique_lock<std::mutex>guard1(a.mut, std::defer_lock);
	// std::cout << std::this_thread::get_id() << ": get the first lock" << std::endl;
	std::cout << std::this_thread::get_id() << ": get the first lock\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	std::unique_lock<std::mutex>guard2(b.mut, std::defer_lock);
	// std::cout << std::this_thread::get_id() << ": get the second lock" << std::endl;
	std::cout << std::this_thread::get_id() << ": get the second lock\n";
	std::cout << std::this_thread::get_id() << ": atomic locking\n";
	lock(guard1, guard2);
}

int main() {

	CriticalData c1;
	CriticalData c2;

	std::thread t1([&] {deadLockResolved(c1, c2); });
	std::thread t2([&] {deadLockResolved(c2, c1); });

	t1.join();
	t2.join();

}

/*
std::unique_lock 호출 시 둘째 인수로 std::defer_lock을 지정했기 때문에, a.mut와 b.mut의 잠금이 지연된다.
두 뮤텍스는 이후 std::lock(guard1, guard2) 호출에서 비로소 잠긴다.
*/