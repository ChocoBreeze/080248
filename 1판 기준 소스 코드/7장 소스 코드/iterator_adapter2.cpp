#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 

using std::vector;
using std::cout;

int main() {
	vector<int> myIntVec;
	std::istream_iterator<int> myIntStreamReader(std::cin);
	std::istream_iterator<int> myEndIterator;

	while (myIntStreamReader != myEndIterator) { // 정수로 해석할 수 없는 값이 입력될 때까지 무한 입력
		myIntVec.push_back(*myIntStreamReader);
		++myIntStreamReader;
	}

	std::copy(begin(myIntVec), end(myIntVec), std::ostream_iterator<int>(std::cout, ":")); // ":"를 구분자로 std::cout에 복사

	return 0;
}