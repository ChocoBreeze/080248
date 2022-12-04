// 메모리 할당

#include <cassert>
#include <iostream>
#include <string>

#include <string_view>

// 글로벌 오버로딩 operator new를 이용하면 메모리 할당을 모두 볼 수 있음.
void* operator new(std::size_t count) {
    std::cout << "   " << count << " bytes" << std::endl;
    return malloc(count);
}

void getString(const std::string& str) {}

void getStringView(std::string_view strView) {}

int main() {

    std::cout << std::endl;

    std::cout << "std::string" << std::endl;
    
    // std::string experi; 16 bytes

    std::string large = "0123456789-123456789-123456789-123456789"; // 48 bytes
    std::string substr = large.substr(10);  // 32 bytes

    std::cout << std::endl;

    std::cout << "std::string_view" << std::endl;

    std::string_view largeStringView{ large.c_str(), large.size() }; // 할당 안 됨
    largeStringView.remove_prefix(10); // 할당 안 됨

    assert(substr == largeStringView);

    std::cout << std::endl;

    std::cout << "getString" << std::endl;

    getString(large);
    getString("0123456789-123456789-123456789-123456789");  // 48 bytes
    const char message[] = "0123456789-123456789-123456789-123456789";
    getString(message); // 48 bytes

    std::cout << std::endl;

    std::cout << "getStringView" << std::endl;

    getStringView(large);   // 할당 안 됨
    getStringView("0123456789-123456789-123456789-123456789"); // 할당 안 됨
    getStringView(message); // 할당 안 됨

    std::cout << std::endl;

}

/*
16 bytes가 출력되는 이유?..
그냥 std::string experi; 라고만 만들어도 16byte가 만들어짐.
디폴트로 할당되는 크기인 듯함.

std::string
   16 bytes
   48 bytes
   16 bytes
   32 bytes

std::string_view

getString
   16 bytes
   48 bytes
   16 bytes
   48 bytes

getStringView

*/
