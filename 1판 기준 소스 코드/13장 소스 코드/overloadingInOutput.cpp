#include <iostream>

class Fraction {
public:
    Fraction(int num = 0, int denom = 0) :numerator(num), denominator(denom) {}

    friend std::istream& operator>> (std::istream& in, Fraction& frac);
    friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);

private:
    int numerator;
    int denominator;
};

std::istream& operator>> (std::istream& in, Fraction& frac) {

    in >> frac.numerator;
    in >> frac.denominator;

    return in;

}

std::ostream& operator<< (std::ostream& out, const Fraction& frac) {

    out << frac.numerator << "/" << frac.denominator;
    return out;
}

int main() {

    std::cout << std::endl;

    Fraction frac(3, 4);
    Fraction frac2(7, 8);
    std::cout << "frac(3, 4): " << frac << std::endl; // 3/4
    std::cout << frac << "   " << frac2 << std::endl; // 3/4    7/8

    std::cout << std::endl;

    std::cout << "Enter two natural numbers for a Fraction: " << std::endl;
    Fraction fracDef;
    std::cin >> fracDef; // 숫자 2개 입력
    std::cout << "fracDef: " << fracDef << std::endl; // 분수 형태로 출력

    std::cout << std::endl;

}