#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

int main() {

    // 현재 경로
    std::cout << "Current path: " << fs::current_path() << std::endl;

    std::string dir = "sandbox/a/b";
    fs::create_directories(dir); // 디렉터리 계층을 생성할 수 있음.

    std::ofstream("sandbox/file1.txt");
    fs::path symPath = fs::current_path() /= "sandbox"; // /= 연산자는 경로에 대해 오버로딩 된 것도 있음.
    symPath /= "syma";
    fs::create_symlink("target", symPath); // 심볼릭 링크를 직접 생성 가능.

    std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
    std::cout << "fs::exists(symPath): " << fs::exists(symPath) << std::endl;
    std::cout << "fs::symlink(symPath): " << fs::is_symlink(symPath) << std::endl;


    for (auto& p : fs::recursive_directory_iterator("sandbox")) // 5 디렉터리를 재귀적으로 탐색이 가능.
        std::cout << p << std::endl;
    fs::remove_all("sandbox");

}

// https://en.cppreference.com/w/cpp/filesystem/create_symlink
/*
create_symlink에서 exception이 발생.
Notes
Some operating systems do not support symbolic links at all or support them only for regular files.
Some file systems do not support symbolic links regardless of the operating system, 
for example the FAT system used on some memory cards and flash drives.

Like a hard link, a symbolic link allows a file to have multiple logical names. 
The presence of a hard link guarantees the existence of a file, even after the original name has been removed. 
A symbolic link provides no such assurance; in fact, the file named by the target argument need not exist when the link is created. 
A symbolic link can cross file system boundaries.
*/