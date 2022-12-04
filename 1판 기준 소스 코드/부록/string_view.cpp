// 수정 연산

#include <iostream>
#include <string>
#include <string_view>

int main() {

    std::string str = "   A lot of space";
    std::string_view strView = str;
    // 시작 지점을 앞으로 줄이기
    strView.remove_prefix(std::min(strView.find_first_not_of(" "), strView.size()));
    std::cout << "str      :  " << str << std::endl
        << "strView  : " << strView << std::endl;

    std::cout << std::endl;

    char arr[] = { 'A', ' ', 'l', 'o', 't', ' ', 'o', 'f', ' ', 's', 'p', 'a', 'c', 'e', '\0',  '\0',  '\0' };
    std::string_view strView2(arr, sizeof arr);
    auto trimPos = strView2.find('\0');
    // 끝 지점을 뒤로 줄이기.
    if (trimPos != strView2.npos) strView2.remove_suffix(strView2.size() - trimPos);
    std::cout << "arr     : " << arr << ", size=" << sizeof arr << std::endl
        << "strView2: " << strView2 << ", size=" << strView2.size() << std::endl;

}

/*
str      :     A lot of space
strView  : A lot of space

arr     : A lot of space, size=17
strView2: A lot of space, size=14
*/