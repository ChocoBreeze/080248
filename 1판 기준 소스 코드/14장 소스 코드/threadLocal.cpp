#include <iostream>
#include <string>
#include <mutex>
#include <thread>

std::mutex coutMutex;

thread_local std::string s("hello from ");

void addThreadLocal(std::string const& s2) {

	s += s2;
	// protect std::cout
	std::lock_guard<std::mutex> guard(coutMutex);
	std::cout << s << std::endl;
	std::cout << "&s: " << &s << std::endl;
	std::cout << std::endl;

}

int main() {

	std::cout << std::endl;
	std::thread t1(addThreadLocal, "t1");
	std::thread t2(addThreadLocal, "t2");
	std::thread t3(addThreadLocal, "t3");
	std::thread t4(addThreadLocal, "t4");

	t1.join();
	t2.join();
	t3.join();
	t4.join();

}
/*
스레드들은 각자 자신만의 스레드 지역 자료를 가진다.
이 예제에서는 thread_local이 지정된 문자열 s가 스레드 지역 자료이다.
네 스레드는 각자 개별적인 s 복사본을 가지며, 따라서 네 스레드는 서로 다른 문자열 주소를 출력한다.
*/