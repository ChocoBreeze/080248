#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

    std::cout << std::endl;

    std::vector<int> myVec{ 0, 1, 2, 3, 4, 5, 6, 7, 9 };
    std::vector<int> myVec2(10);

    for (auto v : myVec) std::cout << v << " ";
    for (auto v : myVec2) std::cout << v << " ";

    std::cout << std::endl;
    std::swap(myVec, myVec2);

    for (auto v : myVec) std::cout << v << " ";
    for (auto v : myVec2) std::cout << v << " ";

    std::cout << "\n\n";

    std::string str{ "abcdefghijklmnop" };
    std::string str2{ "---------------------" };

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    std::swap_ranges(str.begin(), str.begin() + 5, str2.begin() + 5);

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    std::cout << std::endl;

}