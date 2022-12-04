#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

	std::cout << std::endl;

	std::vector<int> myVec{ 0, 1, 2, 3, 4, 5, 6, 7, 9 };
	std::vector<int> myVec2(10);

	std::copy_if(myVec.begin(), myVec.end(), myVec2.begin() + 3, [](int a) { return a % 2; }); // 조건 맞는 애들만 복사
	for (auto v : myVec2) std::cout << v << " ";

	std::cout << "\n\n";

	std::string str{ "abcdefghijklmnop" };
	std::string str2{ "---------------------" };

	std::cout << str2 << std::endl;
	std::copy_backward(str.begin(), str.end(), str2.end()); // 거꾸로 복사
	// str2.end()(끝 지점)부터 str.begin() ~ str.end() 복사
	std::cout << str2 << std::endl;

	std::cout << std::endl;

	std::cout << str << std::endl;
	std::copy_backward(str.begin(), str.begin() + 5, str.end());
	// str.end()(끝 지점)부터 str.begin ~ str.begin() + 5 복사
	std::cout << str << std::endl;

	std::cout << std::endl;

}