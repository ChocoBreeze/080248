#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

bool isOdd(int i) { return (i % 2); }

int main() {

	std::cout << std::boolalpha << std::endl;

	std::vector<int> vec{ 1, 4, 3, 4, 5, 6, 7, 3, 4, 5, 6, 0, 4, 8, 4, 6, 6, 5, 8, 8, 3, 9, 3, 7, 6, 4, 8 };

	for (auto v : vec) std::cout << v << " "; // 1 4 3 4 5 6 7 3 4 5 6 0 4 8 4 6 6 5 8 8 3 9 3 7 6 4 8

	std::cout << "\n\n";

	auto parPoint = std::partition(vec.begin(), vec.end(), isOdd);

	for (auto v : vec) std::cout << v << " "; // 1 7 3 3 5 9 7 3 3 5 5 0 4 8 4 6 6 6 8 8 4 6 4 4 6 4 8
	std::cout << std::endl;
	for (auto v = vec.begin(); v != parPoint; ++v) std::cout << *v << " "; // 1 7 3 3 5 9 7 3 3 5 5 ( true )
	std::cout << std::endl;
	for (auto v = parPoint; v != vec.end(); ++v) std::cout << *v << " "; // 0 4 8 4 6 6 6 8 8 4 6 4 4 6 4 8 ( false )
	std::cout << std::endl; 

	std::cout << std::endl;

	std::cout << "std::is_partitioned(vec.begin(), vec.end(), isOdd): " << std::is_partitioned(vec.begin(), vec.end(), isOdd) << std::endl; // true

	std::cout << "std::partition_point(vec.begin(), vec.end(), isOdd) == parPoint: " << (std::partition_point(vec.begin(), vec.end(), isOdd) == parPoint) << std::endl; // true

	std::cout << std::endl;

	std::list<int> li;
	std::list<int> de;
	std::partition_copy(vec.begin(), vec.end(), std::back_inserter(li), std::back_inserter(de), [](int i) { return i < 5; });

	for (auto v : li) std::cout << v << " "; // 1 3 3 3 3 0 4 4 4 4 4 4
	std::cout << std::endl;
	for (auto v : de) std::cout << v << " "; // 7 5 9 7 5 5 8 6 6 6 8 8 6 6 8

	std::cout << "\n\n";

}