#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm> // std::copy, std::find

using std::deque;
using std::vector;
using std::cout;

int main() {
	deque<int> deq{ 5,6,7,10,11,12 };
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	std::copy(std::find(begin(vec), end(vec), 13), end(vec), std::back_inserter(deq));
	// 13 ~ end(vec)를 deq의 뒤에 push_back

	for (auto& d : deq) cout << d << " "; // 5 6 7 10 11 12 13 14 15
	cout << "\n";

	std::copy(std::find(begin(vec), end(vec), 8), std::find(begin(vec), end(vec), 10), std::inserter(deq, std::find(begin(deq), end(deq), 10)));
	// vec [8, 10) 까지를 deq의 10 원소에 삽입.
	for (auto& d : deq) cout << d << " "; // 5 6 7 8 9 10 11 12 13 14 15
	cout << "\n";

	std::copy(rbegin(vec) + 11, rend(vec), std::front_inserter(deq)); // 4 3 2 1
	for (auto& d : deq) cout << d << " "; // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	cout << "\n";

	return 0;
}