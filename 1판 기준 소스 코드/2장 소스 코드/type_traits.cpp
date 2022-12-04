#include <type_traits>
#include <iostream>

template<typename T>T fac(T a) {
	static_assert(std::is_integral<T>::value, "T는 정수 형식이 아님");
	return a;
}

int main() {
	std::cout << fac(10); // 10
	// fac(10.1); // static_assert failed:
	return 0;
}