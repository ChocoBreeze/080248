#include <functional>
#include <iostream>
#include <string>

void invokeMe(const std::string& s) {
	std::cout << s << ": const" << std::endl;
}

void invokeMe(std::string& s) { 
	// 이 메서드가 없는 경우에는
	// ref, cref 모두 const 메서드를 이용함.
	std::cout << s << ": not const" << std::endl;
}


template <typename T>
void doubleMe(T t) {
	t *= 2;
}

std::string s{ "문자열" };


int main() {
	// 둘다 되긴 함
	invokeMe(std::ref(s)); // 문자열 : not const
	invokeMe(std::cref(s)); // 문자열 : const

	int i = 1;
	std::cout << i << std::endl; // 1

	doubleMe(i);
	std::cout << i << std::endl; // 1

	doubleMe(std::ref(i));
	std::cout << i << std::endl; // 2
}
