#include <iostream>
#include <vector>
#include <algorithm> // for_each

using std::vector;
using std::cout;

struct Square {
	void operator() (int& i) { i = i * i; }
};

int main() {
	vector<int> myVec{1,2,3,4,5,6,7,8,9,10};

	std::for_each(begin(myVec), end(myVec), Square()); // 1 4 9 16 25 36 49 64 81 100
    // 함수 객체 사용 시 객체 생성이 필요
    // Square가 아닌 Square() 적어야 함.

	for (auto& v : myVec) std::cout << v << " "; 
	
    cout << "\n";

	myVec = { 1,2,3,4,5,6,7,8,9,10 };
	// lambda function
	std::for_each(begin(myVec), end(myVec), [](int& i) {i = i * i; }); // 1 4 9 16 25 36 49 64 81 100
	for (auto& v : myVec) std::cout << v << " ";
	
	return 0;
}