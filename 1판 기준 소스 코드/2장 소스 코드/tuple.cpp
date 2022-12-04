#include <iostream>
#include <tuple>

using std::tuple;
using std::make_tuple;
using std::cout;

struct Foo {
    Foo(int first, float second, int third) {
        std::cout << first << ", " << second << ", " << third << "\n";
    }
};

int main()
{
    auto tuple = std::make_tuple(42, 3.14f, 0);
    Foo from_Tuple_foo = std::make_from_tuple<Foo>(std::move(tuple)); // 42, 3.14, 0

    int first = 1, second = 2, third = 3, fourth = 4;
    cout << first << " " << second << " " << third << " " << fourth << "\n"; // 1 2 3 4

    auto tup = std::tie(first, second, third, fourth) = make_tuple(101, 102, 103, 104); 

    cout << std::get<0>(tup) << " " << std::get<1>(tup) << " " << std::get<2>(tup) << " " << std::get<3>(tup) << "\n"; // 101 102 103 104
    cout << first << " " << second << " " << third << " " << fourth << "\n"; // 101 102 103 104

    first = 201;
    std::get<1>(tup) = 202;

    cout << std::get<0>(tup) << " " << std::get<1>(tup) << " " << std::get<2>(tup) << " " << std::get<3>(tup) << "\n"; // 201 202 103 104
    cout << first << " " << second << " " << third << " " << fourth << "\n"; // 201 202 103 104

    int a, b;
    tie(std::ignore, a, std::ignore, b) = tup;
    cout << a << " " << b << "\n"; // 202 104

}
