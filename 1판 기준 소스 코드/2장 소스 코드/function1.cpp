#include <functional>
#include <utility>
#include <map>
#include <iostream>

using std::bind;
using std::function;
using std::make_pair;
using std::map;

map<const char, function<double(double, double)>> tab;


int main() {
	tab.insert(make_pair('+', [](double a, double b) {return a + b; }));
	tab.insert(make_pair('-', [](double a, double b) {return a - b; }));
	tab.insert(make_pair('*', [](double a, double b) {return a * b; }));
	tab.insert(make_pair('/', [](double a, double b) {return a / b; }));


	std::cout << tab['+'](3.5, 4.5) << "\n";
	std::cout << tab['-'](3.5, 4.5) << "\n";
	std::cout << tab['*'](3.5, 4.5) << "\n";
	std::cout << tab['/'](3.5, 4.5) << "\n";
}
