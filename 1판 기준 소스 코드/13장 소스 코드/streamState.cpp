#include <ios>
#include <iostream>

int main() {

    std::cout << std::boolalpha << std::endl;

    std::cout << "In failbit-state: " << std::cin.fail() << std::endl;

    std::cout << std::endl;

    int myInt;
    while (std::cin >> myInt) { // a를 입력
        std::cout << "Output: " << myInt << std::endl;
        std::cout << "In failbit-state: " << std::cin.fail() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "In failbit-state: " << std::endl;
    std::cin.clear();
    std::cout << "In failbit-state: " << std::cin.fail() << std::endl;

    std::cout << std::endl;

}

/*
사용자가 문자 a를 입력하면 스트림 std::cin은 std::ios::failbit 상태가 된다.
따라서 a와 std::cin.fail()의 값은 화면에 표시되지 않는다.
std::cin을 다시 사용하려면 먼저 clear 메서드로 플래그들을 초기화해야 한다.
*/