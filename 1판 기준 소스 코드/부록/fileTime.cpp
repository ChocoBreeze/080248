// https://stackoverflow.com/questions/61030383/how-to-convert-stdfilesystemfile-time-type-to-time-t
// https://en.cppreference.com/w/cpp/filesystem/last_write_time
#define _CRT_SECURE_NO_WARNINGS // asctime unsafe

#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using namespace std::chrono;


int main() {

    fs::path path = fs::current_path() / "rainer.txt";
    std::ofstream(path.c_str());
    auto ftime = fs::last_write_time(path); // 새로 만든 파일을 쓴 시각을 설정함
    // ftime : std::filesystem::file_time_type

    // ftime을 이용해 std::chrono::system_clock 초기화
    // std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);  // to_time_t가 없음(C++20)
    // std::time_t cftime = std::chrono::system_clock::to_time_t(ftime); // file_time_type -> time_point 변환이 적절치 x
    auto systemTime = std::chrono::clock_cast<std::chrono::system_clock>(ftime);
    std::time_t cftime = std::chrono::system_clock::to_time_t(systemTime);
    // fs::file_time_type cftime = decltype(ftime)::clock::time_point(ftime); (기존 코드)

    // std::localtime을 초기화하고 달력 시각을 텍스트로 표현
    std::cout << "Write time on server " << std::asctime(std::localtime(&cftime));
    // std::localtime 대신 std::gmtime(독일 시간)을 사용 -> 
    // 네이버에는 8시간 차이라고 적혀있는데 9시간 차이 남.
    std::cout << "Write time on server " << std::asctime(std::gmtime(&cftime)) << std::endl;

    fs::last_write_time(path, ftime + 2h); // 코드에서 파일을 쓴 시각을 2시간 뒤로 변경
    ftime = fs::last_write_time(path); // 변경된 시간을 파일 시스템에서 읽기

    // cftime = decltype(ftime)::clock::to_time_t(ftime);
    // cftime = std::chrono::system_clock::to_time_t(ftime);
    systemTime = std::chrono::clock_cast<std::chrono::system_clock>(ftime);
    cftime = std::chrono::system_clock::to_time_t(systemTime);


    std::cout << "Local time on client " << std::asctime(std::localtime(&cftime)) << std::endl;

    fs::remove(path);

}

/*
Write time on server Thu Nov 17 19:38:58 2022
Write time on server Thu Nov 17 10:38:58 2022

Local time on client Thu Nov 17 21:38:58 2022
*/