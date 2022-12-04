#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

int main() {

    std::cout << std::endl;

    std::array<int, 10> arr1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::array<int, 5> arr2{ 3, 4, -5, 6, 7 };

    auto fwdIt = std::search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end()); // 시작부터 특정 부분 범위 찾기
    // find_end() : 끝에서부터 둘째 범위를 찾아서 그 시작 위치 돌려줌
    // search_n : 주어진 값과 일치하는 count개의 연속된 요소들을 돌려줌.

    if (fwdIt == arr1.end()) std::cout << "arr2 not in arr1." << std::endl;
    else {
        std::cout << "arr2 at position " << std::distance(arr1.begin(), fwdIt) << " in arr1." << std::endl;
    }

    auto fwdIt2 = std::search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), [](int a, int b) { return std::abs(a) == std::abs(b); });

    if (fwdIt2 == arr1.end()) std::cout << "arr2 not in arr1." << std::endl;
    else {
        std::cout << "arr2 at position " << std::distance(arr1.begin(), fwdIt2) << " in arr1." << std::endl;
    }

    std::cout << std::endl;

}