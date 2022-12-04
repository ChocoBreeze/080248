#include <chrono>
#include <future>
#include <iostream>

using std::chrono::duration;
using std::chrono::system_clock;
using std::launch;
using std::async;

int main() {

	std::cout << std::endl;

	auto begin = system_clock::now();

	auto asyncLazy = async(launch::deferred, [] { return  system_clock::now(); });
	// 현재 스레드에서 비동기 호출
	// std::launch::deferred : the task is executed on the calling thread the first time its result is requested (lazy evaluation)
	// 작업이 처음 결과가 요청될 때 호출 스레드에서 실행됨(예측 평가)

	auto asyncEager = async(launch::async, [] { return  system_clock::now(); });
	// 다른 스레드에서 비동기 호출 실행
	// std::launch::async : the task is executed on a different thread, potentially by creating and launching it first
	// task는 다른 스레드에서 실행될 수 있으며, 먼저 task를 생성하고 실행함.

	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto lazyStart = asyncLazy.get() - begin;
	auto eagerStart = asyncEager.get() - begin;

	auto lazyDuration = duration<double>(lazyStart).count();
	auto eagerDuration = duration<double>(eagerStart).count();

	std::cout << "asyncLazy evaluated after : " << lazyDuration << " seconds." << std::endl; // 1.00924 seconds.
	std::cout << "asyncEager evaluated after: " << eagerDuration << " seconds." << std::endl; // 0.0008642 seconds.

	std::cout << std::endl;

}
/*
미래 객체 asyncLazy에 연관된 약속 객체는 
미래 객체 asyncEager에 연관된 약속보다 1초 늦게 실행된다.
이 1초는 현재 스레드가 미래 객체 asyncLazy의 결과를 조회하기 전에 
std::sleep_for을 이용해서 기다린 시간에 해당한다.

아마도 asyncEager는 다른 스레드에서 실행된 결과 -> 1초 기다리지 않고 결과 알 수 있음.
asyncLazy는 1초 기다린 후에 현재 스레드에서 실행
*/