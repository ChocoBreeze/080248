// 두 조합의 가능성을 시험해 보는 코드
/*
Now:                                    The unofficial name of the new C++ standard is C++0x.
Future:                                 The official name of the new C++ standard is C++11.
*/
#include <regex>

#include <iomanip>
#include <iostream>
#include <string>

int main() {

    std::cout << std::endl;

    std::string future{ "Future" };
    int len = sizeof(future);

    const std::string unofficial{ "unofficial, C++0x" };
    const std::string official{ "official, C++11" };

    std::regex regValues{ "(.*), (.*)" };


    std::string standardText{ "The $1 name of the new C++ standard is $2." };

    // using std::regex_replace
    std::string textNow = std::regex_replace(unofficial, regValues, standardText);
    // 정규 표현식 regValues의 첫째, 둘째 갈무리 그룹과 부합하는 텍스트를 문자열 unofficial에서 추출하고
    // 텍스트 standardText의 자리표 $1과 $2를 추출한 값들로 대체함.

    std::cout << std::setw(len) << std::left << "Now: " << textNow << std::endl;

    // using std::match_results
    // typedef match_results<string::const_iterator> smatch;
    std::smatch smatch;
    if (std::regex_match(official, smatch, regValues)) {

        std::string textFuture = smatch.format(standardText);
        // 위의 std::regex_replace(unofficial, regValues, standardText)와 비슷한 방식으로 동작
        // 차이점은 부합 결과를 담은 smatch의 생성과 그것을 이용한 문자열 서식화가 분리되어 있다는 점.
        std::cout << std::setw(len) << std::left << "Future: " << textFuture << std::endl;

    }

    std::cout << std::endl;

}