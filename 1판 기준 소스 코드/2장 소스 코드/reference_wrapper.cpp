#include <functional>
#include <iostream>

void foo() {
	std::cout << "호출됨" << std::endl;
}

typedef void callableUnit();
std::reference_wrapper<callableUnit> refWrap(foo);

int main() {
	refWrap(); // 호출됨
}
