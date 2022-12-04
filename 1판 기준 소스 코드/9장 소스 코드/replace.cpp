// copy - 함수형 프로그래밍이 될 것 같기도.
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {

	std::cout << std::endl;

	std::string str{ "Only for testing purpose." };

	std::cout << str << std::endl;

	std::replace(str.begin(), str.end(), ' ', '1'); // ' '를 1로 대체
	std::cout << str << std::endl;

	std::replace_if(str.begin(), str.end(), [](char c) { return c == '1'; }, '2'); // 조건 만족 시 '2'로 대체
	std::cout << str << std::endl;

	std::string str2;
	std::replace_copy(str.begin(), str.end(), std::back_inserter(str2), '2', '3'); // '2'를 '3'으로 대체 + 그 결과를 str2가 가리키는 출력 범위에 복사
	std::cout << str2 << std::endl;

	std::string str3;
	std::replace_copy_if(str2.begin(), str2.end(), std::back_inserter(str3), [](char c) { return c == '3'; }, '4'); // 조건 만족시 대체 + 그 결과를 원하는 곳에 복사
	std::cout << str3 << std::endl;

	std::cout << std::endl;

}