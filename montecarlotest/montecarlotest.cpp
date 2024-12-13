#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
    std::vector<int> randomNumbers;

    for(int i = 0; i < 10; i++) {
       randomNumbers.push_back(std::rand()); 
    }
    
    std::sort(randomNumbers.begin(), randomNumbers.end());

    for(const auto& i : randomNumbers) {
        std::cout << "number: " << i << std::endl;
    }

    return 0;
}
