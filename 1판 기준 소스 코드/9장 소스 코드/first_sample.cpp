#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <list>

using std::cout;
using std::vector;
using std::deque;
using std::list;

template <typename Cont, typename T>
void doTheSame(Cont cont, T t) {
	for (const auto& c : cont) cout << c << " ";
	cout << cont.size() << std::endl;
	std::reverse(begin(cont), end(cont));

	for (const auto& c : cont) cout << c << " ";
	std::reverse(begin(cont), end(cont));

	for (const auto& c : cont) cout << c << " ";
	auto It = std::find(begin(cont), end(cont), t);
	std::reverse(It, end(cont));
	for (const auto& c : cont) cout << c << " ";
}

int main() {
	vector<int> myVec{ 1,2,3,4,5,6,7,8,9,10 };
	deque<std::string> myDeq({ "A", "B", "C", "D", "E", "F", "G", "H", "I" });
	list<char> myList({ 'a','b','c','d','e','f','g','h' });

	doTheSame(myVec, 5);

	doTheSame(myDeq, "D");

	doTheSame(myList,'d');

	return 0;
}