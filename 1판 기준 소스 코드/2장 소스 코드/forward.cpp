#include <utility>
#include <vector>
#include <string>

using std::initializer_list;

struct MyData {
	MyData(int, double, char) {};
};

template<typename T, typename... Args>
T createT(Args&&... args) {
	return T(std::forward<Args>(args)...);
}


int main() {

	int a = createT<int>();
	int b = createT<int>(1);

	std::string s = createT<std::string>("시험용 문자열.");
	MyData myData2 = createT<MyData>(1, 3.19, 'a');

	typedef std::vector<int> IntVec;
	IntVec intVec = createT<IntVec>(initializer_list<int>({ 1,2,3 }));

	return 0;
}
