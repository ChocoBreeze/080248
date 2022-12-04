#include <memory>
#include <iostream>

using std::cout;
using std::endl;

class ShareMe : public std::enable_shared_from_this<ShareMe> {
	// 클래스는 디폴트 접근 지정이 private 이지만 구조체의 경우 public 이다
public:
	std::shared_ptr<ShareMe> getShared() {
		return shared_from_this();
	}
};

int main() {
	std::shared_ptr<ShareMe> shareMe(new ShareMe);
	std::shared_ptr<ShareMe> shareMe1 = shareMe->getShared();

	cout << (void*)shareMe.get() << endl;
	cout << (void*)shareMe1.get() << endl;
	cout << shareMe.use_count() << endl; // 2
	
	return 0;
	
}