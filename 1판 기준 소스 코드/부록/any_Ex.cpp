#include <iostream>
#include <string>
#include <any>

using std::any;
using std::string;

struct Position {
	double x, y, z;
};

void f() {
	any a = string("C++ 문자열");

	a = 123; // 새 값이 배정되기 전에 기존 값(string 객체)이 파괴된다(소멸자 호출 및 메모리 해제).

	a = Position{ 1,2,3 }; // 복사할 수 있는 형식이면 어떤 형식도 가능.
}

void g() {
	any a = string("C++ 문자열");
	std::cout << any_cast<string>(a) << std::endl; // C++ 문자열
	
	int i = any_cast<int>(a); // 형식이 일치하지 않음 -> bad_any_cast 예외 발생
}

void h() {
	any a; // 빈 객체
	std::cout << a.has_value() << std::endl; // false

	a.emplace<string>("Hello, world!"); // 제자리 생성
	std::cout << a.type().name() << std::endl; // 구체적인 형식 이름은 컴파일러마다 상이할 수 있음.
	
	a.reset(); // 이제 has_value는 false.
}