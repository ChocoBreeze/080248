#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main() {
	string str{ "123456789" };
	string str1{"_____"}; // 5칸
	std::reverse_copy(begin(str), begin(str) + 5,begin(str1)); // 같은 수의 공간 할당이 필요한 것 같음.
	cout << str1 << "\n";

	cout << str << "\n";
	std::reverse(begin(str), begin(str) + 5);
	cout << str << "\n";


	return 0;
}