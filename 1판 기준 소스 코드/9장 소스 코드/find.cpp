#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <set>

bool isVowel(char c) {

	std::string myVowels{ "aeiouäöü" };
	std::set<char> vowels(myVowels.begin(), myVowels.end());
	auto it = vowels.find(c);
	if (it != vowels.end()) return true;
	return false;


}


int main() {

	std::cout << std::endl;

	std::list<char> myChars{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	int chars[] = { 'A', 'B', 'C' };

	// 범위 안에 한 요소 찾기
	std::cout << "*std::find(myChars.begin(), myChars.end(), 'g'): " << *std::find(myChars.begin(), myChars.end(), 'g') << std::endl;
	std::cout << "std::find_if(myChars.begin(), myChars.end(), isVowel): " << *std::find_if(myChars.begin(), myChars.end(), isVowel) << std::endl;
	std::cout << "std::find_if_not(myChars.begin(), myChars.end(), isVowel): " << *std::find_if_not(myChars.begin(), myChars.end(), isVowel) << std::endl;

	// 범위내에서 처음으로 일치하는 요소 찾기
	auto iter = std::find_first_of(myChars.begin(), myChars.end(), chars, chars + 3);

	if (iter != myChars.end()) std::cout << "Common char: " << *iter << std::endl;
	else std::cout << "None of A, B or C in myChars." << std::endl;

	auto iter2 = std::find_first_of(myChars.begin(), myChars.end(), chars, chars + 3, [](char a, char b) {return std::toupper(a) == std::toupper(b); });

	if (iter2 != myChars.end()) std::cout << "Common char: " << *iter2 << std::endl;
	else std::cout << "None of A, B or C in myChars." << std::endl;

	// 값이 같은 일련의 요소들을 찾기
	auto iter3 = std::adjacent_find(myChars.begin(), myChars.end());

	if (iter3 != myChars.end()) std::cout << "Find char: " << *iter3 << std::endl;
	else std::cout << "No same adjacent characters. " << std::endl;

	auto iter4 = std::adjacent_find(myChars.begin(), myChars.end(), [](char a, char b) { return isVowel(a) == isVowel(b); });

	if (iter4 != myChars.end()) std::cout << "Find adjacent consonants or vowels: " << *iter4 << std::endl;
	else std::cout << "No same adjacent characters. " << std::endl;

	std::cout << std::endl;

}