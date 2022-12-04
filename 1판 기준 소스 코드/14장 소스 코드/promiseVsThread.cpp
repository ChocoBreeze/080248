#include <iostream>
#include <future>
#include <thread>

using std::thread;
using std::async;
using std::cout;
using std::endl;

int main() {
	int res;
	thread t([&] {res = 2000 + 11; });
	t.join();
	cout << res << endl; // 2011

	auto fut = async([] {return 2000 + 11; });
	cout << fut.get() << endl; // 2011

	return 0;
}
/*
자식 스레드 t와 비동기 함수 호출 std::async는 2000과 11의 합을 계산한다.
부모 스레드는 공유 변수 res를 통해서 자식 스레드 t의 결과를 얻는다.
반면 std::async 호출은 송신자(약속)와 수신자(미래) 사이에 자료 채널을 하나 생성한다.
미래 객체는 fut.get()을 이용해서 약속 객체의 계산 결과를 얻는다.
fut.get() 호출은 약속 객체가 결과를 제공할 때까지 차단된다.
*/