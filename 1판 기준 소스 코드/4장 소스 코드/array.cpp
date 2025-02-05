#include <algorithm>
#include <numeric>
#include <array>
#include <iostream>
#include <iterator>

const int NUM = 10;

// https://en.cppreference.com/w/cpp/algorithm/copy

int main() {

	std::cout << std::boolalpha << std::endl;

	std::array<int, 10> arr_trash; // 10개의 요소는 쓰레기 값을 가짐
	std::array<int, 10> arr_default{}; // 해당 요소의 기본값 int의 경우 0으로 초기화된 10칸 배열
	std::array<int, 10> arr_{ 1,2,3,4,5 }; // 명시되지 않은 값들은 기본값으로 초기화됨

	// index 접근
	std::cout << arr_[0] << "\n";
	std::cout << arr_.at(0) << "\n";
	std::cout << std::get<0>(arr_) << "\n";

	// no value initialized
	std::array<int, NUM> arr1;
	std::cout << "arr1: ";
	std::copy(arr1.begin(), arr1.end(), std::ostream_iterator<int>(std::cout, " ")); // copy인데 이렇게도 출력할 수 있구나


	// value-initialization
	std::array<int, NUM> arr2 = {};
	std::cout << std::endl << "arr2:  ";
	std::array<int, NUM>::const_iterator arrIt;
	for (arrIt = arr2.begin(); arrIt != arr2.end(); ++arrIt) std::cout << *arrIt << " ";

	std::array<int, NUM> arr3{ 1, 2, 3, 4 };
	std::cout << std::endl << "arr3: ";
	for (auto a : arr3) std::cout << a << " ";

	// initializer list
	std::array<int, NUM> arr4{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << std::endl << "arr4: ";
	std::copy(arr4.rbegin(), arr4.rend(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\n\n";

	// get the size of arr4
	double sum = std::accumulate(arr4.begin(), arr4.end(), 0);
	double mean = sum / arr4.size();
	std::cout << "mean of a4: " << mean << std::endl;

	std::cout << std::endl;

	// read and write
	std::cout << "arr4[5]: " << arr4[5] << std::endl;
	std::cout << "arr4.at(5): " << arr4.at(5) << std::endl;
	arr4[5] = 2011;
	std::cout << "arr4[5]: " << arr4[5] << std::endl;

	// swap arrays
	std::swap(arr1, arr4);
	std::cout << std::endl << "arr4: ";
	for (auto a : arr4) std::cout << a << " ";

	std::cout << "\n\n";

	// comparison
	std::cout << "(arr1 < arr4): " << (arr1 < arr4) << std::endl;

	std::cout << std::endl;

	// tuple like
	std::cout << "(arr4[0] == std::get<0>(arr4)): " << (arr4[0] == std::get<0>(arr4)) << std::endl;

	std::cout << std::endl;

}