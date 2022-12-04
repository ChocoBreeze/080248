#include <utility>
#include <vector>

std::vector<int> myBigVec(10000000, 2011);
std::vector<int> myVec;

int main() {
	myVec = myBigVec; // copy
	myVec = std::move(myBigVec);

	return 0;
}
