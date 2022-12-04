#include <iostream>
#include <string>

int main() {

	std::cout << std::endl;

	std::string str{ "C++-String" };
	std::cout << "str : " << str << std::endl;
	str += " C-String";
	std::cout << "str : " << str << std::endl;

	const char* cString = str.c_str();
	std::cout << "cString : " << cString << std::endl;

	char buffer[10];
	str.copy(buffer, 10); // 자동으로 '\0' 추가해주지 않는다. 출력하면 끝을 알 수 없다.
	std::cout << "buffer : " << buffer << std::endl;

	str += " works";
	
	const char* cString2= cString;  // ERROR - 옛날에는 에러였는데, 지금은 잘 되는 듯?

	std::cout << std::endl << std::endl;
	std::cout << "str : " << str << std::endl;
	std::cout << "cString : " << cString << std::endl;
	std::cout << "cString2 : " << cString2 << std::endl;
	std::cout << "buffer : " << buffer << std::endl;

	std::string str2(buffer, buffer + 10);
	std::cout << "str2 : " << str2 << std::endl;

	std::cout << std::endl;

}