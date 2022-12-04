#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string toString(int i) {
	std::stringstream buff;
	buff.str("");
	buff << i;
	std::string val = buff.str();
	return val;
}

int toInt(const std::string& s) {
	std::stringstream buff;
	buff.str("");
	buff << s;
	int value;
	buff >> value;
	return value;
}


int main() {

	std::cout << std::endl;

	std::vector<int> myInts;
	std::vector<std::string> myStrings{ "94", "5", "39", "-4", "-49", "1001", "-77", "23", "0", "84", "59", "96", "6", "-94", "87" };
	std::transform(myStrings.begin(), myStrings.end(), std::back_inserter(myInts), toInt);

	for (auto i : myInts) std::cout << i << " ";

	std::cout << "\n\n";

	auto paInt = std::minmax_element(myInts.begin(), myInts.end()); // 최소, 최대
	std::cout << "std::minmax_element(myInts.begin(), myInts.end(): " << "(" << *paInt.first << ", " << *paInt.second << ")" << std::endl;
	// (-94, 1001) (숫자)

	auto paStr = std::minmax_element(myStrings.begin(), myStrings.end());
	std::cout << "std::minmax_element(myStrings.begin(), myStrings.end(): " << "(" << *paStr.first << ", " << *paStr.second << ")" << std::endl;
	// (-4, 96) (스트링)

	auto paStrAsInt = std::minmax_element(myStrings.begin(), myStrings.end(), [](std::string a, std::string b) { return toInt(a) < toInt(b); });
	std::cout << "std::minmax_element(myStrings.begin(), myStrings.end(): " << "(" << *paStr.first << ", " << *paStr.second << ")" << std::endl;
	// (-4, 96) int로 바꿨는데 왜 string처럼 나오는거지?

	std::cout << std::endl;

}