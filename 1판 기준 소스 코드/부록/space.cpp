// https://en.cppreference.com/w/cpp/filesystem/space
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {

    fs::space_info root = fs::space("/");
    // fs::space_info usr = fs::space("/usr"); // error (windows)
    
    fs::space_info cur_space = fs::space(fs::current_path());
    // fs::space_info null_space = fs::space("/null");

    std::cout << "              Capacity       Free         Available\n"
        << "/           " << root.capacity << "   "
        << root.free << "   " << root.available << "\n"
        /* << "usr  " << usr.capacity << "   "
        << usr.free << "   " << usr.available;*/
        << "cur path    " << cur_space.capacity << "   "
        << cur_space.free << "   " << cur_space.available << "\n";
        /* << "null " << null_space.capacity << "   "
        << null_space.free << "   " << null_space.available << "\n";*/

    return 0;
}
/*
              Capacity       Free         Available
/           499422269440   326724739072   326724739072
cur path    499422269440   326724739072   326724739072

동일한 파일 시스템에 대한 경로이므로 결과가 같은 듯.

*/
