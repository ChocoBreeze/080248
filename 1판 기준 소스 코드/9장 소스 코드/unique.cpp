#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

template <typename T>
void print_Vec(vector<T>& vec) {
	for (auto& v : vec) std::cout << v << " ";
	cout << "\n";
}

int main() {

	vector<int> myVec{ 0,0, 1,1, 2,2, 3,4, 4, 5,3, 6, 7, 8,1,3,3,8,8, 9 };
	
	myVec.erase(std::unique(begin(myVec), end(myVec)), end(myVec));

	print_Vec(myVec); // 0 1 2 3 4 5 3 6 7 8 1 3 8 9

	vector<int> myVec2{ 1,4,3,3,3,5,7,9,2,4,1,6,8,0,3,5,7,8,7,3,9,2,4,2,5,7,3 };

	vector<int> resVec;
	resVec.reserve(myVec2.size());
	std::unique_copy(begin(myVec2), end(myVec2), std::back_inserter(resVec), [](int a, int b) {
		return (a % 2) == (b % 2); });

	print_Vec(myVec2); // 1 4 3 3 3 5 7 9 2 4 1 6 8 0 3 5 7 8 7 3 9 2 4 2 5 7 3

	print_Vec(resVec); // 1 4 3 2 1 6 3 8 7 2 5

	
	return 0;
}