#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFromFile(const char* fileName) {
    // getline을 이용해서 파일의 모든 행을 읽어서 벡터 객체에 추가함.
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Could not open the file " << fileName << ".";
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> lines;
    std::string line;
    while (getline(file, line)) lines.push_back(line);

    return lines;

}

int main() {

    std::cout << std::endl;

    std::string fileName;
    std::cout << "Your filename: ";
    std::cin >> fileName; // 파일 이름을 스트림에서 읽기

    std::vector<std::string> lines = readFromFile(fileName.c_str());

    int num{ 0 };
    for (auto line : lines) std::cout << ++num << ": " << line << std::endl;

    std::cout << std::endl;

}
