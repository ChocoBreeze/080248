// 여러 정규 표현식의 처음 네 부분 부합(submatch; 갈무리 그룹과 부합한 부분)을 출력한다,.
/*
      reg Expr        text   smatch[0] smatch[1] smatch[2] smatch[3] smatch[4]
          abc+     abccccc     abccccc
  (a+)(b+)(c+)     aaabccc     aaabccc       aaa         b       ccc
((a+)(b+)(c+))     aaabccc     aaabccc   aaabccc       aaa         b       ccc
    (ab)(abc)+    ababcabc    ababcabc        ab       abc
*/
#include <regex>

#include <iomanip>
#include <iostream>
#include <string>

void showCaptureGroups(const std::string& regEx, const std::string& text) {

    // regular expression holder
    std::regex rgx(regEx);

    // result holder
    std::smatch smatch;

    // result evaluation
    if (std::regex_search(text, smatch, rgx)) {
        std::cout << std::setw(14) << regEx << std::setw(12) << text 
            << std::setw(12) << smatch[0] << std::setw(10) << smatch[1] 
            << std::setw(10) << smatch[2] << std::setw(10) << smatch[3] 
            << std::setw(10) << smatch[4] << std::endl;
    }

}

int main() {

    std::cout << std::endl;

    std::cout << std::setw(14) << "reg Expr" << std::setw(12) << "text" 
        << std::setw(12) << "smatch[0]" << std::setw(10) << "smatch[1]" 
        << std::setw(10) << "smatch[2]" << std::setw(10) << "smatch[3]" 
        << std::setw(10) << "smatch[4]" << std::endl;

    showCaptureGroups("abc+", "abccccc");

    showCaptureGroups("(a+)(b+)(c+)", "aaabccc");

    showCaptureGroups("((a+)(b+)(c+))", "aaabccc");

    showCaptureGroups("(ab)(abc)+", "ababcabc");

    std::cout << std::endl;

}