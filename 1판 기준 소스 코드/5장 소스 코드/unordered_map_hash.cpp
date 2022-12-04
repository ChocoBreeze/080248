#include <iostream>
#include <ostream> // 굳이?
#include <unordered_map>

struct MyInt {
    MyInt(int v) :val(v) {}
    bool operator== (const MyInt& other) const { // 사용자 정의 값에 대한 상등 비교
        return val == other.val;
    }
    int val;
};

struct MyHash {
    std::size_t operator()(MyInt m) const { // 사용자 정의 형식에 대한 해시 함수
        std::hash<int> hashVal;
        return hashVal(m.val);
    }
};

std::ostream& operator << (std::ostream& strm, const MyInt& myIn) {
    strm << "MyInt(" << myIn.val << ")";
    return strm;
}

int main() {

    std::cout << std::endl;

    std::hash<int> hashVal;

    // a few hash values
    for (int i = -2; i <= 1; ++i) {
        std::cout << "hashVal(" << i << "): " << hashVal(i) << std::endl;
    }

    std::cout << std::endl;

    typedef std::unordered_map<MyInt, int, MyHash> MyIntMap;    // key, value, hashfuntion

    std::cout << "MyIntMap: ";
    MyIntMap myMap{ {MyInt(-2), -2}, {MyInt(-1), -1}, {MyInt(0), 0}, {MyInt(1), 1} };

    for (auto m : myMap) std::cout << "{" << m.first << ", " << m.second << "}";

    std::cout << std::endl << std::endl;

}