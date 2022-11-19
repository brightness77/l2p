#include "maos.h"
#include<iostream>

#include<map>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<bitset>



std::bitset<32> toBinary(int n) {
    std::bitset<32> result(n);
    return result;
}



int main(int argc, char * argv[]) {
    char c = 0b00001111;

    for (int i = 0; i < 40; i++) {
        std::cout << "c left shift " << i << " got: " << toBinary(c << i) << std::endl;
    }

    int i1 = c;
    for (int i = 0; i < 40; i++) {
        i1 <<= 1;
        std::cout << "i1 left shift " << i << " got: " << toBinary(i1) << std::endl;
    }

    return 0;
}












