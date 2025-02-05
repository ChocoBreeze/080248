#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>

namespace fs = std::filesystem;

void printStatus(const fs::path& path_) {
    std::cout << path_;
    if (!fs::exists(path_)) std::cout << " does not exist";
    else {
        if (fs::is_block_file(path_)) std::cout << " is a block file\n";
        if (fs::is_character_file(path_)) std::cout << " is a character device\n";
        if (fs::is_directory(path_)) std::cout << " is a directory\n";
        if (fs::is_fifo(path_)) std::cout << " is a named pipe\n";
        if (fs::is_regular_file(path_)) std::cout << " is a regular file\n";
        if (fs::is_socket(path_)) std::cout << " is a socket\n";
        if (fs::is_symlink(path_)) std::cout << "          is a symlink\n";
    }
}

int main() {

    fs::create_directory("rainer");
    printStatus("rainer");

    std::ofstream("rainer/regularFile.txt");
    printStatus("rainer/regularFile.txt");

    fs::create_directory("rainer/directory");
    printStatus("rainer/directory");

    mkfifo("rainer/namedPipe", 0644);
    printStatus("rainer/namedPipe");

    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    std::strcpy(addr.sun_path, "rainer/socket");
    int fd = socket(PF_UNIX, SOCK_STREAM, 0);
    bind(fd, (struct sockaddr*)&addr, sizeof addr);
    printStatus("rainer/socket");

    fs::create_symlink("rainer/regularFile.txt", "symlink");
    printStatus("symlink");

    printStatus("dummy.txt");

    fs::remove_all("rainer");

}

/*
아쉽지만 직접 실행해보지 않음.
*/