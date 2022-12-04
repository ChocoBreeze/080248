#include <iostream>
#include <fstream>
#include <execution>

void i() {
	int x = 0;
	std::mutex m;
	int a[] = { 1,2 };
	std::for_each(std::execution::par, std::begin(a), std::end(a), [&](int) {
		std::lock_guard<std::mutex> guard(m);
		++x;
	});
}

void j() {
	int x = 0;
	std::mutex m;
	int a[] = { 1,2 };
	std::for_each(std::execution::par_unseq, std::begin(a), std::end(a), [&](int) {
		std::lock_guard<std::mutex> guard(m);
		++x;
	});
}