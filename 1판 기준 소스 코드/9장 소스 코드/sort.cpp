#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

    std::cout << std::boolalpha << std::endl;

    std::string str{ "RUdAjdDkaACsdfjwldXmnEiVSEZTiepfgOIkue" };

    std::cout << str << std::endl;

    std::cout << "std::is_sorted(str.begin(), str.end()): " << std::is_sorted(str.begin(), str.end()) << std::endl; // false

    std::cout << std::endl;

    std::partial_sort(str.begin(), str.begin() + 30, str.end()); // 부분 정렬
    std::cout << str << std::endl; // AACDEEIORSTUVXZaddddeeffgiijjkwspnmluk
    auto sortUntil = std::is_sorted_until(str.begin(), str.end()); // 정렬 기준을 만족하지 않는 첫 원소 반환
    std::cout << "Sorted unitl: " << *sortUntil << std::endl; // s
    for (auto charIt = str.begin(); charIt != sortUntil; ++charIt) std::cout << *charIt; // AACDEEIORSTUVXZaddddeeffgiijjkw

    std::cout << "\n\n";

    std::vector<int> vec{ 1, 0, 4, 3, 5 };

    auto vecIt = vec.begin();
    while (vecIt != vec.end()) {
        std::nth_element(vec.begin(), vecIt++, vec.end()); // n번째 위치에 정확한 요소가 놓일 때까지만 범위 정렬
        std::cout << std::distance(vec.begin(), vecIt) << "-th ";
        for (auto v : vec) std::cout << v;
        std::cout << std::endl;
    }

    std::cout << std::endl;

}