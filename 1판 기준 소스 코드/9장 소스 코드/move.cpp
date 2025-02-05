#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

    std::cout << std::endl;

    std::vector<int> myVec{ 0, 1, 2, 3, 4, 5, 6, 7, 9 };
    std::vector<int> myVec2(10);

    std::move(myVec.begin(), myVec.end(), myVec2.begin()); // 앞에서부터
    for (auto v : myVec2) std::cout << v << " ";

    std::cout << "\n\n";

    std::string str{ "abcdefghijklmnop" };
    std::string str2{ "---------------------" };

    std::cout << str2 << std::endl;
    std::move_backward(str.begin(), str.end(), str2.end()); // 뒤에서부터
    std::cout << str2 << std::endl;

    std::cout << std::endl;

}