#include <iostream>
#include <variant>
#include <string>

using std::string;
using std::variant;
using std::cout;
using std::endl;

void f() {
	variant<int, double, string> v = 123;
	// cout << v << endl; // 123 - 이러한 연산자를 사용하는 변환이 없음.!
	cout << std::get<int>(v) << endl; // 명시적으로 int를 요청. 
	cout << std::get<0>(v) << endl; // 첫 번째 형식(int)의 값을 요청

	// auto f = std::get<float>(v); // (1) 컴파일 오류
	// auto cond = std::get<string>(v); // (2) 실행 시점 예외 발생

}

void g() {
	variant<int, double, bool> v = 123;

	// (1)
	auto pv = std::get_if<bool>(&v); // pv는 nullptr
	// std::get과는 달리 std::get_if는 포인터를 받으며, 
	// 형식 불일치 시 예외 대신 널 포인터를 돌려줌.

	// (2)
	auto cond = std::holds_alternative<int>(v); // cond는 true
	// std::holds_alternative<T>(v)는 현재 v 객체의 형식이 
	// T인지의 여부를 뜻하는 bool 값을 돌려준다.

	// (3)
	auto i = v.index(); // i는 0
	// 멤버 변수 index는 현재 형식의 색인을 돌려준다. 지금 예에서 int가 0, double 1, bool이 2이다.
	// 이 색인은 std::get<i>(v) 형태로 활용할 수 있다.
}

int main() {
	f();
	return 0;
}