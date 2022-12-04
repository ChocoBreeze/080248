#include <iostream>
#include <thread>

using namespace std;

void printStringCopy(string s) { cout << s; }
void printStringRef(const string& s) { cout << s; }

int main() {
	string s{ "C++" };

	// 인수 s를 복사로 전달
	thread tPerCopy([=] {cout << s; }); // C++
	thread tPerCopy2(printStringCopy, s); // C++

	tPerCopy.join();
	tPerCopy2.join();

	// 인수 s를 참조로 전달
	thread tPerReference([&] {cout << s; }); // C++
	thread tPerReference2(printStringRef, s); // C++

	tPerReference.join();
	tPerReference2.join();
}