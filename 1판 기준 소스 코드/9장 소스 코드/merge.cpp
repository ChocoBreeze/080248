#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

	std::cout << std::boolalpha << std::endl;

	std::vector<int> vec1{ 1, 1, 4, 3, 5, 8, 6, 7, 9, 2 };
	std::vector<int> vec2{ 1, 2, 3 };

	std::sort(vec1.begin(), vec1.end());
	std::vector<int> vec(vec1);

	std::cout << "std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()): " << std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()) << std::endl; // true

	std::cout << std::endl;

	vec1.reserve(vec1.size() + vec2.size());
	vec1.insert(vec1.end(), vec2.begin(), vec2.end());
	for (auto v : vec1) std::cout << v << " "; // 1 1 2 3 4 5 6 7 8 9 1 2 3

	std::cout << std::endl;

	std::inplace_merge(vec1.begin(), vec1.end() - vec2.size(), vec1.end());
	for (auto v : vec1) std::cout << v << " "; // 1 1 1 2 2 3 3 4 5 6 7 8 9

	std::cout << "\n\n";

	vec2.push_back(10);

	std::cout << "vec:                      ";
	for (auto v : vec) std::cout << v << " ";
	std::cout << std::endl;
	std::cout << "vec2:                     ";
	for (auto v : vec2) std::cout << v << " ";

	// 합집합
	std::vector<int> res;
	std::set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
		std::back_inserter(res));
	std::cout << "\n" << "set_union:                ";
	for (auto v : res) std::cout << v << " ";

	// 교집합
	res = {};
	std::set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
		std::back_inserter(res));
	std::cout << "\n" << "set_intersection:         ";
	for (auto v : res) std::cout << v << " ";

	// 차집합
	res = {};
	std::set_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
		std::back_inserter(res));
	std::cout << "\n" << "set_difference:           ";
	for (auto v : res) std::cout << v << " ";

	// 대칭 차집합
	res = {};
	std::set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
		std::back_inserter(res));
	std::cout << "\n" << "set_symmetric_difference: ";
	for (auto v : res) std::cout << v << " ";


	std::cout << "\n\n";

}