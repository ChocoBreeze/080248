#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using std::vector;

template <typename T>
void print_Vec(vector<T>& vec) {
	for (auto& v : vec) std::cout << v << " ";
}

int main() {

	std::cout << std::endl;

	vector<int> vec1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vec2(vec1);

	print_Vec(vec1);
	// for (auto& v : vec1) std::cout << v << " ";

	std::cout << std::endl;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::cout << std::endl;

	// std::random_shuffle(vec1.begin(), vec1.end()); C++17에서 제거
	// for (auto& v : vec1) std::cout << v << " ";

	std::cout << std::endl;

	std::shuffle(vec2.begin(), vec2.end(), std::default_random_engine(seed));
	print_Vec(vec2);
	// for (auto& v : vec2) std::cout << v << " ";

	std::cout << "\n\n";

}