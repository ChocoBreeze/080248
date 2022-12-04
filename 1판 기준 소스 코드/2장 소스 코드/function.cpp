#include <functional>
#include <iostream>

// 자리표(placeholder) _1과 _2를 위한 이름공간 선언
using namespace std::placeholders;

using std::bind;
using std::function;

double divMe(double a, double b) { return a / b; };
function<double(double, double)> myDiv1 = bind(divMe, _1, _2);
function<double(double)> myDiv2 = bind(divMe, 2000, _1);

int main() {
	std::cout << divMe(2000, 10) << "\n"; // 200
	std::cout << myDiv1(2000, 10) << "\n"; // 200
	std::cout << myDiv2(10) << "\n"; // 200
	// divMe(2000, 10) == myDiv1(2000, 10) == myDiv2(10);
}