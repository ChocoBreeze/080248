#include <iostream>
#include <limits>
#include <string>

int main() {

    std::cout << std::endl;

    std::cout << "to_string, to_wstring" << std::endl;

    std::string maxLongLongString = std::to_string(std::numeric_limits<long long>::max());
    std::wstring maxLongLongWstring = std::to_wstring(std::numeric_limits<long long>::max());

    std::cout << std::numeric_limits<long long>::max() << std::endl;
    std::cout << maxLongLongString << std::endl; // 9223372036854775807
    std::wcout << maxLongLongWstring << std::endl; // 9223372036854775807

    std::cout << std::endl;

    std::cout << "ato* " << std::endl;

    std::string str("10010101");

    std::cout << std::stoi(str) << std::endl; // 10010101
    std::cout << std::stoi(str, nullptr, 16) << std::endl; // 268501249
    std::cout << std::stoi(str, nullptr, 8) << std::endl; // 2101313
    std::cout << std::stoi(str, nullptr, 2) << std::endl; // 149

    std::cout << std::endl;

    std::size_t idx;
    std::cout << std::stod("   3.5 km", &idx) << std::endl; // 3.5
    std::cout << "Not numeric char at position " << idx << "." << std::endl; // 6.
    // 둘째 인수(포인터)가 지정된 경우, 
    // 함수는 유효하지 않은(수치의 일부가 아닌) 첫 문자의 색인을 그 인수를 통해서 돌려준다.

    std::cout << std::endl;

    try {
        std::cout << std::stoi("   3.5 km") << std::endl; // 3
        std::cout << std::stoi("   3.5 km", nullptr, 2) << std::endl; // exception
        // (string, pos, base)
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl; // invalid stoi argument 
        // 변환이 불가능한 경우 std::invalid_argument 예외를 던짐
    }

    std::cout << std::endl;

}