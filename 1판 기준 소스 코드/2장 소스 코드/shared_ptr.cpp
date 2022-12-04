#include <memory>
#include <iostream>

using std::cout;
using std::endl;

class MyInt {
public:
	MyInt(int v) : val(v) {
		cout << "진입 : " << val << endl;
	}
	~MyInt() {
		cout << "퇴장 : " << val << endl;
	}
private:
	int val;
};

int main() {
	auto sharPtr = std::make_shared<MyInt>(1998); // 진입 : 1998
	cout << sharPtr.use_count() << endl; // 1

	{
		std::shared_ptr<MyInt> locSharPtr(sharPtr);
		cout << locSharPtr.use_count() << endl; // 2
	}
	cout << sharPtr.use_count() << endl; // 1

	std::shared_ptr<MyInt> globSharPtr(sharPtr);
	cout << sharPtr.use_count() << endl; // 2

	globSharPtr.reset();
	cout << sharPtr.use_count() << endl; // 1
	sharPtr = std::shared_ptr<MyInt>(new MyInt(2011)); // 진입 : 2011

	return 0;
	// 퇴장 : 1998
	// 퇴장 : 2011
}