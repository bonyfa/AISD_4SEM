#include <iostream>
#include <set.h>
#include <ctime>
#include <chrono>
#include <vector>

#define SEC_IN_MILLISEC 1000 

size_t lcg() {//generate random value
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

int main() {
    binary_tree bt(3);
    bt.insert(5);
    bt.insert(6);
    bt.insert(3);
    bt.insert(2);
    bt.insert(5);
    bt.insert(7);
    bt.print();
    std::cout << std::endl;

    //std::chrono::time_point<std::chrono::system_clock> start, end;
    //double sum = 0;
    //erase and find
    ////binary_tree set;
    //std::vector<int> vec;
    //for (size_t i = 0; i < 10000; ++i) {
    //    //set.insert(lcg());
    //    vec.push_back(lcg());
    //}
    //for (size_t g = 0; g < 1000; ++g) {
    //    start = std::chrono::system_clock::now();
    //    std::find(vec.begin(), vec.end(), lcg());
    //    std::remove(vec.begin(), vec.end(), lcg());
    //    //set.insert(lcg());
    //    //set.erase(lcg());
    //    end = std::chrono::system_clock::now();
    //    std::chrono::duration<double> elapsed_seconds = end - start;
    //    sum += elapsed_seconds.count();
    //}

    //insert
    //for (size_t g = 0; g < 100; ++g) {
    //    start = std::chrono::system_clock::now();
    //    binary_tree set;
    //    //std::vector<int> vec;
    //    for (size_t i = 0; i < 100000; ++i) {
    //        set.insert(lcg());
    //        //vec.push_back(lcg());
    //    }
    //    end = std::chrono::system_clock::now();
    //    std::chrono::duration<double> elapsed_seconds = end - start;
    //    sum += elapsed_seconds.count();
    //}

    //search
    //binary_tree set;
    //std::vector<int> vec;
    //for (size_t i = 0; i < 10000; ++i) {
    //    //set.insert(lcg());
    //    vec.push_back(lcg());
    //}
    //for (size_t g = 0; g < 1000; ++g) {
    //    start = std::chrono::system_clock::now();
    //    std::find(vec.begin(), vec.end(), lcg());
    //    //set.contains(lcg());
    //    end = std::chrono::system_clock::now();
    //    std::chrono::duration<double> elapsed_seconds = end - start;
    //    sum += elapsed_seconds.count();
    //}
    //std::cout << "elapsed time: " << (sum/1000)*SEC_IN_MILLISEC << "\n";
    return 0;
}