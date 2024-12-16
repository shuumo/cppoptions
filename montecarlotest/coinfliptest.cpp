/* 
 * This file is just to test how mt19937 library in c++ <random> library works
 * */
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

#define FLIP_COUNT 100

int main(int argc, char **argv) {
    std::mt19937 mt(time(nullptr)); 
    unsigned int flipValue;
    
    std::string flipString = "TAILS"; 
    int headsCount = 0;
     
    std::vector<char> patternMatch(3, '0');
    int patternCount = 0;

    for(int i = 0; i < FLIP_COUNT; i++) {
        flipValue = mt();
        if(flipValue >= mt.max()/2) {
            flipString = "HEADS";
            headsCount++;
        }
        std::cout << "Coin " << i+1 << " flipped: " << flipString << std::endl;
        
        patternMatch.erase(patternMatch.begin());
        patternMatch.push_back(flipString.at(0));

        if(patternMatch[0] == 'H' && patternMatch[1] == 'T' && patternMatch[2] == 'H') {
            patternCount++;
        }

        flipString = "TAILS";
    }

    std::cout << std::endl;

    std::cout << "Total flips: " << FLIP_COUNT << std::endl;
    std::cout << "Number of times the coin flipped Heads: " << headsCount << std::endl;
    std::cout << "Number of times the coin flipped Tails: " << FLIP_COUNT-headsCount << std::endl;

    std::cout << "Heads, Tails then Heads appeared in sequence " << patternCount << " times during the simulation." << std::endl;
    return 0;
}
