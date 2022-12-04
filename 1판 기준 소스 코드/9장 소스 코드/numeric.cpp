#include <array>
#include <iostream>
#include <numeric> // 필요
#include <vector>


int main() {

	std::cout << std::endl;

	std::array<int, 9> arr{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "std::accumulate(arr.begin(), arr.end(), 0): " << std::accumulate(arr.begin(), arr.end(), 0) << std::endl; // 45
	std::cout << "std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b){ return  a+b;}): " << std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b) { return  a * b; }) << std::endl; // 362880

	std::cout << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> myVec;

	std::cout << "adjacent_difference: " << std::endl;
	std::adjacent_difference(vec.begin(), vec.end(), std::back_inserter(myVec), [](int a, int b) { return a * b; });
	for (auto v : vec) std::cout << v << " "; // 1 2 3 4 5 6 7 8 9
	std::cout << std::endl;
	for (auto v : myVec) std::cout << v << " "; // 1 2 6 12 20 30 42 56 72

	std::cout << "\n\n";

	std::cout << "std::inner_product(vec.begin(), vec.end(), arr.begin(), 0): " << std::inner_product(vec.begin(), vec.end(), arr.begin(), 0) << std::endl; // 285

	std::cout << std::endl;

	myVec = {};
	std::partial_sum(vec.begin(), vec.end(), std::back_inserter(myVec));
	std::cout << "partial_sum: ";
	for (auto v : myVec) std::cout << v << " "; // 1 3 6 10 15 21 28 36 45

	std::cout << "\n\n";

	std::cout << "iota: ";
	std::vector<int> myLongVec(100);
	std::iota(myLongVec.begin(), myLongVec.end(), 2000); // val로 시작해서 1씩 증가하는 값을 범위의 각 요소에 배정하는 알고리즘.

	for (auto v : myLongVec) std::cout << v << " ";

	std::cout << "\n\n";

}