#include <iostream>
#include <string>

int main() {

	std::cout << std::boolalpha << std::endl;

	std::string first{ "aaa" };
	std::string second{ "aaaa" };

	// 문자열 비교 - 같은 위치의 요소들을 비교하는 식으로 진행함
	std::cout << "first <  first :" << (first < first) << std::endl; // false
	std::cout << "first <=  first :" << (first <= first) << std::endl; // true
	std::cout << "first <  second :" << (first < second) << std::endl; // true

	std::cout << std::endl;

	std::string one{ "1" };
	std::string oneOneOne = one + std::string("1") + "1";

	std::cout << "1 + 1 + 1: " << oneOneOne << std::endl; // 111

	std::cout << std::endl;

}