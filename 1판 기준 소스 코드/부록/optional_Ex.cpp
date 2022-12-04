#include <iostream>
#include <string>
#include <optional>
#include <map>

using std::optional;
using std::string;
using std::map;

map<string, int> options; // 이름-값 쌍

optional<int> get_option(const string& name) {
	// options는 이름-값 쌍들을 담은 전역 std::map 객체라고 가정.
	auto match = options.find(name);
	if (match != options.end()) {
		return match->second;
	}
	else {
		return {};
	}
}

void f() {
	auto val = get_option("WIDTH");
	auto r1 = val; // r1은 val의 복사본(std::optional<int> 객체).
	auto r2 = val.has_value(); // r2는 bool.

	optional<string> opt1; // string 값을 담을 수 있는 빈 optional 객체.
	// 이 경우에는 string을 명시적으로 지정해야 함.
	opt1.emplace<string>("hello"); // string 객체가 opt1 안에서 직접 생성된다.

	auto opt2 = std::make_optional(10); 
	// 인수 10으로부터 int가 연역되므로 int를 명시적으로 지정할 필요 없음.
	opt2.reset(); // 값을 삭제
	std::cout << opt2.value(); // 값이 없는 optional 객체에 대해 value()를 호출하면
	// std::bad_optional_access 예외가 발생함.

	// 설정 파일에서 창의 너비 값을 가져와서 설정하되,
	// 만일 설정된 값이 없으면 기본적인 800으로 설정한다.
	window.set_width(get_option("WIDTH").value_or(800));


	if (val) {
		std::cout << "창 너비 : " << *val << std::endl;
	}
	else {
		// ... 오류 처리 ...
	}
}
