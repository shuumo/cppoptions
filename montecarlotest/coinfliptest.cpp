#include <iostream>
#include <random>
#include <ctime>

#define FLIP_COUNT 10000

int main(int argc, char **argv) {
    std::mt19937 mt(time(nullptr)); 
    unsigned int flipValue;
    
    std::string flipString = "TAILS";
    
    int headsCount = 0;

    for(int i = 0; i < FLIP_COUNT; i++) {
        flipValue = mt();
        if(flipValue >= mt.max()/2) {
            flipString = "HEADS";
            headsCount++;
        } 
        std::cout << "Coin " << i+1 << " flipped: " << flipString << std::endl;
        flipString = "TAILS";
    }
    
    std::cout << std::endl;

    std::cout << "Total flips: " << FLIP_COUNT << std::endl;
    std::cout << "Number of times the coin flipped Heads: " << headsCount << std::endl; 
    std::cout << "Number of times the coin flipped Tails: " << FLIP_COUNT-headsCount << std::endl;

    return 0;
}
