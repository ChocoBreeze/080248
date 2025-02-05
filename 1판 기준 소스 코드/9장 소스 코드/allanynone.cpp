#include <algorithm>
#include <iostream>
#include <vector>

int main(){

  std::cout << std::boolalpha << std::endl;

  auto even= [](int i){ return i%2;};

  std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "std::any_of(myVec.begin(), myVec.end(), even): " << std::any_of(myVec.begin(), myVec.end(), even) << std::endl; // 하나라도 있는가
  std::cout << "std::all_of(myVec.begin(), myVec.end(), even): " << std::all_of(myVec.begin(), myVec.end(), even) << std::endl; // 모두 그러한가
  std::cout << "std::none_of(myVec.begin(), myVec.end(), even: " << std::none_of(myVec.begin(), myVec.end(), even) << std::endl; // 하나도 없는가
  
 std::cout << std::endl;

}