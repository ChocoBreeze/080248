#include <iostream>
#include <utility>
#include <memory>

using namespace std;

class MyStruct {
public:
	MyStruct() : val(count) {
		cout << (void*)this << " 진입 : " << val << endl;
		MyStruct::count++;
	}
	~MyStruct() {
		cout << (void*)this << " 퇴장 : " << val << endl;
		MyStruct::count--;
	}
	static int get_count() {
		return count;
	}
private:
	int val;
	static int count;
};

// https://m.blog.naver.com/tipsware/221676342281 참고
int MyStruct::count = 0;

struct MyInt {
	MyInt(int i) : i_(i) {}
	~MyInt() {
		cout << "퇴장: " << i_ << endl;
	}
	int i_;
};

int main() {
	unique_ptr<MyInt> uniquePtr1{ new MyInt(1998) };
	cout << uniquePtr1.get() << endl; 

	unique_ptr<MyInt> uniquePtr2{ move(uniquePtr1)};
	cout << uniquePtr1.get() << endl;
	cout << uniquePtr2.get() << endl;
	{
		unique_ptr<MyInt> localPtr{ new MyInt(2003) };
	} // 퇴장: 2003
	uniquePtr2.reset(new MyInt(2011)); // 퇴장 : 1998
	MyInt* myInt = uniquePtr2.release();
	delete myInt; // 퇴장 : 2011

	unique_ptr<MyInt> uniquePtr3{ new MyInt(2017) };
	unique_ptr<MyInt> uniquePtr4{ new MyInt(2022) };
	cout << uniquePtr3.get() << endl;
	cout << uniquePtr4.get() << endl;

	swap(uniquePtr3, uniquePtr4);
	cout << uniquePtr3.get() << endl;
	cout << uniquePtr4.get() << endl;


	// std::unique_ptr에는 배열을 위한 특수화(specialization)가 있다.
	unique_ptr<MyStruct[]> myUniqueArray{ new MyStruct[3] };

	/*
	0000016A80D790D8 진입 : 0
	0000016A80D790DC 진입 : 1
	0000016A80D790E0 진입 : 2
	0000016A80D790E0 퇴장 : 2
	0000016A80D790DC 퇴장 : 1
	0000016A80D790D8 퇴장 : 0
	*/

	return 0;
	
}