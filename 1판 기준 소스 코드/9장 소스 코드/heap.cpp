#include <algorithm>
#include <iostream>
#include <vector>

int main() {

	std::cout << std::boolalpha << std::endl;

	std::vector<int> vec{ 4, 3, 2, 1, 5, 6, 7, 9, 10 };
	for (auto v : vec) std::cout << v << " ";
	std::cout << std::endl;

	std::make_heap(vec.begin(), vec.end());
	for (auto v : vec) std::cout << v << " "; // 10 9 7 4 5 6 2 3 1
	std::cout << std::endl;

	std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl; // true

	std::cout << std::endl;

	vec.push_back(100);
	std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl; // false
	std::cout << "*std::is_heap_until(vec.begin(), vec.end()): " << *std::is_heap_until(vec.begin(), vec.end()) << std::endl; // 100
	// 처음으로 heap이 아닌 원소 반환
	for (auto v : vec) std::cout << v << " ";
	std::push_heap(vec.begin(), vec.end()); // 범위의 마지막 요소를 힙에 삽입
	std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl; // true
	std::cout << std::endl;
	for (auto v : vec) std::cout << v << " ";

	std::cout << "\n\n";

	std::pop_heap(vec.begin(), vec.end()); // 힙에서 가장 큰 요소를 제거 후 범위의 끝으로 이동
	for (auto v : vec) std::cout << v << " ";
	std::cout << std::endl;
	std::cout << "*std::is_heap_until(vec.begin(), vec.end()): " << *std::is_heap_until(vec.begin(), vec.end()) << std::endl; // 100
	vec.resize(vec.size() - 1);
	std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl; // true

	std::cout << std::endl;

	std::cout << "vec.front(): " << vec.front() << std::endl; // 10

	std::cout << std::endl;

}