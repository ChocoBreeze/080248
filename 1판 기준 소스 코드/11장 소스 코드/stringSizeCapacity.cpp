#include <iostream>
#include <string>

void showStringInfo(const std::string& s) {

	std::cout << s << std::endl;
	std::cout << "s.size(): " << s.size() << std::endl; // s.length()와 동일
	std::cout << "s.capacity(): " << s.capacity() << std::endl; // 재할당 없이 담을 수있는 최대 크기
	std::cout << "s.max_size(): " << s.max_size() << std::endl; // 시스템에서 가능한 최대 크기
	std::cout << std::endl;

}

int main() {

	std::string str;
	showStringInfo(str); // 0, 15, 9223372036854775807

	str += "12345";
	showStringInfo(str); // 5, 15, 9223372036854775807

	str.resize(30);
	showStringInfo(str); // 30, 31, 9223372036854775807

	str.reserve(1000);
	showStringInfo(str); // 30, 1007, 9223372036854775807

	str.shrink_to_fit();
	showStringInfo(str); // 30, 31, 9223372036854775807

}