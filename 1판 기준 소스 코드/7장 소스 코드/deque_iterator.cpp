// deque 반복자
// 임의 접근 가능하다..
#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> DQ;
	for (int i = 0; i < 10; ++i) {
		DQ.push_back(i);
	}
	cout << DQ[5]; // 5
	return 0;
}