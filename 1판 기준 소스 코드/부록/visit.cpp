#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>

#include <variant>


int main() {

    std::vector<std::variant<char, long, float, int, double, long long>>      // 1
        vecVariant = { 5, '2', 5.4, 100ll, 2011l, 3.5f, 2017 };

    // display each value   
    std::cout << "Display Each Value \n";
    for (auto& v : vecVariant) {
        std::visit([](auto&& arg) {std::cout << arg << " "; }, v);  // 2
    }

    std::cout << std::endl << std::endl;

    std::cout << "Display Each Type \n";
    // display each type
    for (auto& v : vecVariant) {
        std::visit([](auto&& arg) {std::cout << typeid(arg).name() << " "; }, v); // 3
    }

    std::cout << std::endl << std::endl;

    // get the sum
    // 올바른 결과 타입을 컴파일 시간에 지정하기 위해서
    // type trait 라이브러리에서 제공하는 std::common_type 사용
    std::common_type<char, long, float, int, double, long long>::type res{};  // 4(double -> 0.0)

    std::cout << "typeid(res).name(): " << typeid(res).name() << std::endl << std::endl;

    for (auto& v : vecVariant) {
        std::visit([&res](auto&& arg) {res += arg; }, v);                          // 5
    }
    std::cout << "Sum(res): " << res << std::endl << std::endl;

    // double each value
    for (auto& v : vecVariant) {
        std::visit([&res](auto&& arg) {arg *= 2; }, v);                           // 6
        std::visit([](auto&& arg) {std::cout << arg << " "; }, v);
    }

    std::cout << std::endl;

}