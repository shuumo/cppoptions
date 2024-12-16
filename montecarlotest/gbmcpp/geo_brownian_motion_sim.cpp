#include <iostream>
#include "matplotlibcpp.h"
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xbuilder.hpp"
#include "xtensor/xrandom.hpp"
#include "xtensor/xmath.hpp"
#include <cmath>
#include <ctime>
#include <vector>
#include <chrono>

namespace plt = matplotlibcpp;

// modifyable parameters
#define SIM_COUNT 5       //Number of GBM simulations to plot
#define MU 0.04           //(%) drift over years
#define SIGMA 0.18        //(%) volatility over years
#define NUM_OF_YEARS 1    //(years)
#define START_PRICE 200   //($) initial prices of simulaitons


std::vector<double> createGbmSimXValues(int years, double mu, double sigma, double startprice) {      
    // change in time (years)
    double dt = 1.0/365.0;

    // mean of log returns
    double m = (mu - 0.5 * std::pow(sigma, 2));
    
    // volatility of log returns
    double s = sigma;
    
    // daily log returns
    auto logreturn = xt::random::randn({(1/dt)*years}, m*dt, s * std::sqrt(dt));

    // daily raw returns 
    auto returns = xt::exp(logreturn) - 1;

    // daily prices when S0=1
    auto price = xt::exp(xt::cumsum(logreturn)) * startprice;

    std::vector<double> pricesVector(price.begin(), price.end());
    return pricesVector;
}



int main(int argc, char **argv) { 
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    xt::random::seed(seed);

    std::vector<std::vector<double>> simulationList;
    for(int simNumber = 0; simNumber < SIM_COUNT; simNumber++) {
        simulationList.push_back(
                createGbmSimXValues(NUM_OF_YEARS, MU, SIGMA, START_PRICE)
                ); 
    
    }
    int lengthOfChange = simulationList[0].size();
    auto times = xt::linspace<double>(0., (double) lengthOfChange, lengthOfChange);
    std::vector<double> changeInTime(times.begin(), times.end()); 

    for(const auto& sim : simulationList) {
        plt::plot(changeInTime, sim);
    }

    plt::show();
    return 0;
}

