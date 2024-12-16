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

namespace plt = matplotlibcpp;

// modifyable parameters
#define MU 0.04           //(%)
#define SIGMA 0.18        //(%)
#define NUM_OF_YEARS 2    //(years)

int main(int argc, char **argv) { 
    xt::random::seed(time(nullptr));

    // drift (over years) 
    double mu = MU;
     
    // volatility (over years)
    double sigma = SIGMA;

    // change in time (years)
    double dt = 1.0/365.0;

    // mean of log returns
    double m = (mu - 0.5 * std::pow(sigma, 2));
    
    // volatility of log returns
    double s = sigma;
    
    // daily log returns
    auto logreturn = xt::random::randn({(1/dt)*NUM_OF_YEARS}, m*dt, s * std::sqrt(dt));

    // daily raw returns 
    auto returns = xt::exp(logreturn) - 1;

    // daily prices assuming S0=1
    auto price = xt::exp(xt::cumsum(logreturn));
    
    
    std::cout << "mu: " << mu << std::endl;
    std::cout << "sigma: " << sigma << std::endl;
    std::cout << "dt: " << dt << std::endl;
    std::cout << "m: " << m << std::endl;
    std::cout << "s: " << s << std::endl; 
    
    std::vector<double> changeInPrice(price.begin(), price.end()); 
    std::cout << "time change of simulation: " << changeInPrice.size() << std::endl; 

    auto times = xt::linspace<double>(0., (double) changeInPrice.size(), changeInPrice.size());
    std::vector<double> changeInTime(times.begin(), times.end());
    
    for(const auto& i : changeInPrice) {
        std::cout << i << std::endl;
    }

    plt::plot(changeInTime, changeInPrice);
    plt::show();

    return 0;
}

