#include <optional>
#include <iostream>
#include <vector>

std::optional<int> getFirst(const std::vector<int>& vec) {
    if (!vec.empty()) return std::optional<int>(vec[0]);
    else return std::optional<int>();
}

int main() {

    std::vector<int> myVec{ 1, 2, 3 };
    std::vector<int> myEmptyVec;

    auto myInt = getFirst(myVec);

    if (myInt) {
        std::cout << "*myInt: " << *myInt << std::endl; // 1
        std::cout << "myInt.value(): " << myInt.value() << std::endl; // 1(값을 리턴)
        std::cout << "myInt.value_or(2017):" << myInt.value_or(2017) << std::endl; // 1(값을 리턴하거나 디폴트 값을 리턴)
    }

    std::cout << std::endl;

    auto myEmptyInt = getFirst(myEmptyVec);

    if (!myEmptyInt) {
        std::cout << "myEmptyInt.value_or(2017):" << myEmptyInt.value_or(2017) << std::endl; // 2017
    }
}
