#include "dg_dense_hash_map.h"
#include <chrono>
#include <iostream>

int main(){

    const size_t SZ = size_t{1} << 23;
    size_t total = 0u;

    dg::dense_hash_map::unordered_node_map<uint32_t, uint32_t, uint32_t> map{};

    auto then = std::chrono::high_resolution_clock::now();

    for (size_t i = 0u; i < SZ; ++i){
        map[i] = i;
    }

    // for (size_t i = 0u; i < SZ; ++i){
    //     total += map.find(i)->second;
    // }

    for (size_t i = 0u; i < SZ; ++i){
        map.erase(i);
    }

    // // map.clear();

    for (size_t i = 0u; i < SZ; ++i){
        map[i] = i;
    }

    // for (size_t i = 0u; i < SZ; ++i){
    //     total += ceil2(static_cast<uint32_t>(i));
    //     // std::cout << i << "<>" << ceil2(i) << std::endl;
    // }

    auto now = std::chrono::high_resolution_clock::now();
    auto lapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - then).count();

    std::cout << map.size() << "<total>" << lapsed << "<ms>" << std::endl;
}