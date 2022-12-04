#include <algorithm>
#include <iostream>
#include <string>

int main() {

    std::cout << std::endl;

    std::string str{ "123456789" };

    auto endIt = str.end(); // 미리 정해야 정지 가능.(계속 돈다)
    for (auto middleIt = str.begin(); middleIt != endIt; ++middleIt) {
        std::rotate(str.begin(), middleIt, str.end());
        std::cout << str << std::endl;
        /*
            middleIt = 1 123456789
            middleIt = 2 234567891 -> middleIt = 3
            middleIt = 4 456789123 -> middleIt = 6
            middleIt = 7 789123456 -> middleIt = 1
            middleIt = 2 234567891 -> middleIt = 6
            middleIt = 7 789123456 -> middleIt = 3
            middleIt = 4 456789123 -> middleIt = 1
            middleIt = 2 234567891 -> middleIt = 9
            middleIt = 1 123456789 -> middleIt = 9
            middleIt = str.end(); -> break;
        */
    }

    std::cout << std::endl;

}