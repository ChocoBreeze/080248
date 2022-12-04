/*
std::regex_match의 간단한 용법 3가지
같은 정규식을 각각 C 문자열, C++ 문자열, 그리고 문자 순차열의 한 범위와 부합해서 
그 결과(bool)에 따라 적절한 메시지를 출력함.
이 예에서는 std::regex_match의 반환값(bool)만 사용하지만, std::regex_match에는 상세한
부합 결과를 저장할 std::match_results 객체를 받는 버전도 있다. 
이 때 std::match_results의 구체적인 형식은 
적용 대상(이 예에서는 C 문자열, C++ 문자열, 문자 순차열 범위)의 문자 형식에 따라 결정된다.
 
*/
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {

    std::cout << std::endl;

    // regular expression for a number, not including an exponent
    std::string numberRegEx(R"([-+]?([0-9]*\.[0-9]+|[0-9]+))");

    // regular expression holder
    std::regex rgx(numberRegEx);

    // using const char* (C 문자열)
    const char* numChar{ "2011" };
    if (std::regex_match(numChar, rgx)) {
        std::cout << numChar << " is a number." << std::endl;
    }

    // using std::string (C++ 문자열)
    const std::string numStr{ "3.14159265359" };
    if (std::regex_match(numStr, rgx)) {
        std::cout << numStr << " is a number." << std::endl;
    }

    // using bidirectional iterators (문자 순차열)
    const std::vector<char> numVec{ {'-', '2', '.', '7', '1', '8', '2', '8', '1', '8', '2', '8'} };
    if (std::regex_match(numVec.begin(), numVec.end(), rgx)) {
        for (auto c : numVec) { std::cout << c; };
        std::cout << " is a number." << std::endl;
    }

    std::cout << std::endl;

}