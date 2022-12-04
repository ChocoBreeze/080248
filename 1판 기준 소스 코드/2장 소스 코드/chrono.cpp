// 간단한 성능 측정
#include <chrono>
#include <iostream>
#include <vector>

std::vector<int> myBigVec(10000000, 2011);
std::vector<int> myEmptyVec1;

int main() {
	auto begin = std::chrono::high_resolution_clock::now();
	myEmptyVec1 = myBigVec;
	auto end = std::chrono::high_resolution_clock::now() - begin;

	auto timeInSeconds = std::chrono::duration<double>(end).count();
	std::cout << timeInSeconds << std::endl;

	return 0;
}
