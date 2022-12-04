#include <memory>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	
	auto sharedPtr = std::make_shared<int>(2011);
	std::weak_ptr<int> weakPtr(sharedPtr);

	cout << weakPtr.use_count() << endl;	// 1
	cout << sharedPtr.use_count() << endl;	// 1

	std::shared_ptr sharedPtr2 = sharedPtr;
	cout << weakPtr.use_count() << endl;	// 2
	cout << sharedPtr.use_count() << endl;	// 2

	cout << std::boolalpha << weakPtr.expired() << std::noboolalpha << endl;	// false
	if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
		cout << *sharedPtr << endl; // 2011
	}
	else {
		cout << "자원 획득 실패!" << endl;
	}
	weakPtr.reset(); // 자원 재설정

	if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
		cout << *sharedPtr << endl; 
	}
	else {
		cout << "자원 획득 실패!" << endl; // 자원 획득 실패!
	}

	return 0;
}