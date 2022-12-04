// 파일의 접근 권한 조작하기
#include <fstream>
#include <bitset>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void printPerms(fs::perms perm) {
    std::cout << ((perm & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((perm & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((perm & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((perm & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((perm & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((perm & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((perm & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((perm & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((perm & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << std::endl;
}


int main() {

    std::ofstream("rainer.txt");

    std::cout << "Initial file permissions for a file: ";
    printPerms(fs::status("rainer.txt").permissions()); // rainer.txt 파일에 대한 접근 권한 얻기 + 출력

    fs::permissions("rainer.txt",
        fs::perms::owner_all | fs::perms::group_all,
        fs::perm_options::add); // 이 파일의 소유자와 그룹에 대한 접근 권한 추가
    std::cout << "Adding all bits to owner and group:  ";
    printPerms(fs::status("rainer.txt").permissions());

    fs::permissions("rainer.txt",
        fs::perms::owner_write | fs::perms::group_write | fs::perms::others_write,
        fs::perm_options::remove); // 삭제 권한 지정 가능
    std::cout << "Removing the write bits for all:     ";
    printPerms(fs::status("rainer.txt").permissions());

    fs::remove("rainer.txt");

}

/*
Initial file permissions for a file: rwxrwxrwx
Adding all bits to owner and group:  rwxrwxrwx
Removing the write bits for all:     r-xr-xr-x
*/