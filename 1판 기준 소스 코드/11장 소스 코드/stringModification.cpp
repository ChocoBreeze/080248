#include <iostream>
#include <string>

int main() {

	std::cout << std::endl;

	std::cout << "ASSIGN: " << std::endl;

	std::string str{ "New String" };
	std::string str2{ "Other String" };
	std::cout << "str: " << str << std::endl; // New String

	str.assign(str2, 4, std::string::npos);
	std::cout << str << std::endl; // r String

	str.assign(5, '-'); 
	std::cout << str << std::endl; // -----
	std::cout << std::endl;

	std::cout << "DELETE" << std::endl;

	str = { "0123456789" };
	std::cout << "str: " << str << std::endl; // 0123456789
	str.erase(7, 2);
	std::cout << str << std::endl; // 01234569

	str.erase(str.begin() + 2, str.end() - 2);
	std::cout << str << std::endl; // 0169

	str.erase(str.begin() + 2, str.end());
	std::cout << str << std::endl; // 01

	str.pop_back();
	std::cout << str << std::endl; // 0

	str.erase();
	std::cout << str << std::endl; // ""

	std::cout << "APPEND" << std::endl;

	str = "01234";
	std::cout << "str: " << str << std::endl; // 01234

	str += "56";
	std::cout << str << std::endl; // 0123456

	str += '7';
	std::cout << str << std::endl; // 01234567

	str += {'8', '9'};
	std::cout << str << std::endl; // 0123456789

	str.append(str);
	std::cout << str << std::endl; // 01234567890123456789

	str.append(str, 2, 4);
	std::cout << str << std::endl; // 012345678901234567892345

	str.append(10, '0');
	std::cout << str << std::endl; // 0123456789012345678923450000000000

	str.append(str, 10, 10);
	std::cout << str << std::endl; // 0123456789012345678923450000000000123456789

	str.push_back('9');
	std::cout << str << std::endl; // 01234567890123456789234500000000001234567899

	std::cout << std::endl;

	std::cout << "INSERT" << std::endl;
	str = { "345" };
	std::cout << "str: " << str << std::endl; // 345

	str.insert(3, "6789");
	std::cout << str << std::endl; // 3456789

	str.insert(0, "012");
	std::cout << str << std::endl; // 0123456789

	std::cout << std::endl;

	std::cout << "REPLACE" << std::endl;
	str = { "only for testing purpose." };
	std::cout << "str: " << str << std::endl; // only for testing purpose.

	str.replace(0, 0, "O");
	std::cout << str << std::endl; // Oonly for testing purpose.

	str.replace(0, 5, "Only", 0, 4);
	std::cout << str << std::endl; // Only for testing purpose.

	str.replace(16, 8, "");
	std::cout << str << std::endl; // only for testing.

	str.replace(4, 0, 5, 'y');
	std::cout << str << std::endl; // onlyyyyyy for testing.

	str.replace(str.begin(), str.end(), "Only for testing purpose.");
	std::cout << str << std::endl; // Only for testing purpose.

	str.replace(str.begin() + 4, str.end() - 8, 10, '#');
	std::cout << str << std::endl; // Only##########purpose.

	std::cout << std::endl;

}