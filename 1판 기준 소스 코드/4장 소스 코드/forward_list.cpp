#include <iostream>
#include <forward_list>
#include <iterator>

using std::forward_list;
using std::cout;
using std::endl;

int main() {
	
	cout << std::boolalpha;
	forward_list<int> l1 = { 1,2,3,4,5 };
	forward_list<int> l2{ 1,2,3,4,5 };

	forward_list<int>::iterator it = l1.begin();
	cout << *it << endl;
	it++;
	cout << *it << endl;
	// it--; // 뒤로 못감(코드 상에서도 오류)
	// std::advance(it, -1); // 실행 상황에 가서 오류 발견이 가능(코드 상에서는 오류 감지 x)
	cout << *it << endl;
	
	return 0;
}