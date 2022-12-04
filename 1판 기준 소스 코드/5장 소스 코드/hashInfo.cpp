#include <iostream>
#include <random>
#include <unordered_set>

void getInfo(const std::unordered_set<int>& hash) {

    std::cout << "hash.bucket_count(): " << hash.bucket_count() << std::endl; // returns the number of buckets
    std::cout << "hash.load_factor(): " << hash.load_factor() << std::endl; // returns average number of elements per bucket

}

void fillHash(std::unordered_set<int>& h, int n) {

    std::random_device seed;
    // default generator
    std::mt19937 engine(seed());
    // get random numbers 0 - 1000
    std::uniform_int_distribution<> uniformDist(0, 1000);

    for (int i = 1; i <= n; ++i) {
        h.insert(uniformDist(engine));
    }

}

int main() {

    std::cout << std::endl;

    std::unordered_set<int> hash;
    std::cout << "hash.max_load_factor(): " << hash.max_load_factor() << std::endl; // manages maximum average number of elements per bucket
    // parameter 값을 통해 max load factor 설정도 가능

    std::cout << std::endl;

    getInfo(hash);

    std::cout << std::endl;

    // only to be sure
    hash.insert(500);
    // get the bucket of 500
    std::cout << "hash.bucket(500): " << hash.bucket(500) << std::endl; // Returns the index of the bucket for key key

    std::cout << std::endl;

    // add 100 elements - 무작위로 100개의 값 추가
    fillHash(hash, 100);
    getInfo(hash);

    std::cout << std::endl;

    // at least 500 buckets
    std::cout << "hash.rehash(500): " << std::endl;
    hash.rehash(500); // new number of buckets = 500

    std::cout << std::endl;

    getInfo(hash);

    std::cout << std::endl;

    // get the bucket of 500
    std::cout << "hash.bucket(500): " << hash.bucket(500) << std::endl;

    std::cout << std::endl;

}