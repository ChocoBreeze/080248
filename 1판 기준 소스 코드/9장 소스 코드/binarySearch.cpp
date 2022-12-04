#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool isLessAbs(int a, int b) {
	return std::abs(a) < std::abs(b);
}

int main() {

	std::cout << std::boolalpha << std::endl;

	std::vector<int> vec{ -3, 0, -3, 2, -3, 5, -3, 7, -0, 6, -3, 5, -6, 8, 9, 0, 8, 7, -7, 8, 9, -6, 3, -3, 2 };

	for (auto v : vec) std::cout << v << " "; // -3 0 -3 2 -3 5 -3 7 0 6 -3 5 -6 8 9 0 8 7 -7 8 9 -6 3 -3 2

	std::sort(vec.begin(), vec.end(), isLessAbs); // 절대값 오름차순 정렬
	std::cout << std::endl;
	for (auto v : vec) std::cout << v << " "; // 0 0 0 2 2 -3 -3 -3 -3 -3 3 -3 5 5 6 -6 -6 7 7 -7 8 8 8 9 9

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "std::binary_search(vec.begin(), vec.end(), -5, isLessAbs): " << std::binary_search(vec.begin(), vec.end(), -5, isLessAbs) << std::endl; // true
	std::cout << "std::binary_search(vec.begin(), vec.end(), 5, isLessAbs): " << std::binary_search(vec.begin(), vec.end(), 5, isLessAbs) << std::endl; // true

	auto pair = std::equal_range(vec.begin(), vec.end(), 3, isLessAbs); // lower_bound, upper_bound

	std::cout << std::endl;

	std::cout << "Position of first 3: " << std::distance(vec.begin(), pair.first) << std::endl; // 5
	std::cout << "Position of last 3: " << std::distance(vec.begin(), pair.second) - 1 << std::endl; // 11
	for (auto threeIt = pair.first; threeIt != pair.second; ++threeIt) std::cout << *threeIt << " "; // -3 -3 -3 -3 -3 3 -3

	std::cout << "\n\n";

}