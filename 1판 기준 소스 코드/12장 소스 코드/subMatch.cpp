// 검색 결과를 담은 std::match_results 객체와 
// 그에 담긴 부분 부합 std::sub_match 객체들을 함께
// 사용하는 방법을 보여주는 예제 코드.
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

int main() {

    std::cout << std::endl;

    std::string privateAddress = "192.168.178.21";

    // regular expression for IP4 adresses
    //std::string ip4RegEx(R"((\d{1, 3})\.(\d{1, 3})\.(\d{1, 3})\.(\d{1, 3}))");
    std::string ip4RegEx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");

    // regular expression holder
    std::regex rgx(ip4RegEx);

    // search result holder
    std::smatch smatch; // match results

    // looking for the exact match
    if (std::regex_match(privateAddress, smatch, rgx)) {

        for (auto cap : smatch) {

            std::cout << "capture group: " << cap << std::endl;
            if (cap.matched) {

                // print each character in hexadecimal notation,  including the base
                std::cout << "hex: ";
                std::for_each(cap.first, cap.second, [](int v) {std::cout << std::showbase << std::hex << v << " "; });
                // first : Start of the match sequence. (begin)
                // second : One-past-the-end of the match sequence. (end)
                std::cout << "\n\n";

            }

        }

    }

}