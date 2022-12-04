#include <variant>
#include <iostream>
#include <string>

int main() {

    std::variant<int, float> v, w;  // 둘 다 int와 float 값을 가질 수 있음.
    // v, w의 디폴트 값은 int의 디폴트 값인 0이 된다.

    v = 12;                              // v contains int
    int i = std::get<int>(v);            // type으로 조회하기.
    w = std::get<int>(v);
    w = std::get<0>(v);                  // same effect as the previous line(인덱스로 조회하기 - 0번 index는 int) 
    w = v;                               // same effect as the previous line 

    // type 지정 -> 반드시 고유해야 하고
    // index로 지정 -> 올바른 범위의 값이어야 함!
    // std::get<double>(v);             // error: no double in [int, float]
    // std::get<3>(v);                  // error: valid index values are 0 and 1

    try {
        // w는 int형 값이기 때문에 float 타입을 조회하면 exception이 발생한다.
        std::get<float>(w);                // w contains int, not float: will throw
    }
    catch (std::bad_variant_access&) {
        std::cout << "Bad Variant Access\n";
    }

    // 생성자를 호출하거나 대입문을 실행할 때 모호하지 않다면 변환된다.
    // 그래서 C 스트링으로부터 std::variant<std::string>을 만들거나 
    // 새로운 C 스트링을 variant에 대입할 수 있다.
    std::variant<std::string> sv("abc");  // converting constructors work when unambiguous(모호하지 않아야 생성자가 변환된다)
    sv = "def";                           // converting assignment also works when unambiguous(모호하지 않아야 대입이 변환된다)

}