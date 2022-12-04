// 둘 다 순차적으로 메모리에 저장됨.
#include <iostream>
#include <vector>
#include <array>

using std::vector;
using std::array;
using std::cout;
using std::endl;

int main() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	array<int, 10> arr{ 1,2,3,4,5,6,7,8,9,10 };
	
	cout << std::boolalpha;
	for (int i = 0; i < 10; ++i) {
		// cout << vec[i] == *(vec + i) << std::endl;
		// 안 됨.
		cout << (vec[i] == *(vec.begin() + i)) << " ";
	}

	cout << endl;

	for (int i = 0; i < 10; ++i) {
		// cout << arr[i] == *(arr + i) << std::endl;
		// 안 됨.
		cout << (vec[i] == *(arr.begin() + i)) << " ";
	}
	
	return 0;
}