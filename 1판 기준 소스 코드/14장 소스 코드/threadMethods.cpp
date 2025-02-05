#include <iostream>
#include <thread>


int main() {

	std::cout << std::endl;

	// CPU 코어 개수
	std::cout << "std::thread::hardware_concurrency()= " << std::thread::hardware_concurrency() << std::endl;

	std::cout << std::endl;

	std::thread t1([] {std::cout << "hello from t1 with id= " << std::this_thread::get_id() << std::endl; });
	std::thread t2([] {std::cout << "hello from t2 with id= " << std::this_thread::get_id() << std::endl; });

	std::cout << std::endl;

	std::cout << "FROM MAIN: id of t1 " << t1.get_id() << std::endl;
	std::cout << "FROM MAIN: id of t2 " << t2.get_id() << std::endl;

	std::cout << std::endl;
	t1.swap(t2); // 이동이 가능한 경우 이동 연산 수행
	// thread는 복사는 불가능하고 이동만 가능함.

	std::cout << "FROM MAIN: id of t1 " << t1.get_id() << std::endl;
	std::cout << "FROM MAIN: id of t2 " << t2.get_id() << std::endl;

	std::cout << std::endl;

	std::cout << "FROM MAIN: id of main= " << std::this_thread::get_id() << std::endl;

	t1.join();
	t2.join();

	std::cout << std::endl;

}