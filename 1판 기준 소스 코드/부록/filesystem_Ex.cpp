#include <iostream>
#include <fstream>
#include <filesystem>

void h() {
	namespace fs = std::filesystem;

	fs::create_directory("foo");

	// create_directories는 경로 중간의 디렉터리들까지 생성해준다.
	fs::create_directories("foo/bar/abc/123");

	// 보통의 파일을 생성하려면 파일 입출력 라이브러리가 필요하다.
	std::ofstream("foo/bar/abc/file.txt");

	// 반복자를 이용해서 foo 디렉터리와 그 하위 디렉터리의 모든 항목을 훑는다.
	for (auto&& x : fs::recursive_directory_iterator("foo")) { 
		std::cout << x.path() << std::endl;
	}
}