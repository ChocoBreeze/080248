#include <iostream>
#include <string>
#include <vector>
#include <any>

struct MyClass {};

int main() {

    std::cout << std::boolalpha;

    // std::vector<std::any> anyVec(true, 2017, std::string("test"), 3.14, MyClass());
    std::vector<std::any> anyVec{ true, 2017, std::string("test"), 3.14, MyClass() };
    std::cout << "std::any_cast<bool>anyVec[0]: " << std::any_cast<bool>(anyVec[0]) << std::endl; // true
    int myInt = std::any_cast<int>(anyVec[1]);
    std::cout << "myInt: " << myInt << std::endl << std::endl;                                    // 2017

    std::cout << "anyVec[0].type().name(): " << anyVec[0].type().name() << std::endl;             // bool
    std::cout << "anyVec[1].type().name(): " << anyVec[1].type().name() << std::endl;             // int

}
/*
이 코드는 std::vector<std::any>를 정의함.
벡터 원소 하나를 가져오려면 std::any_cast를 사용해야 함.
타입을 잘못 지정하는 경우, std::bad_any_cast exception이 발생한다.
*/