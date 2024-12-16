#include <iostream>
#include "matplotlibcpp.h"
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xbuilder.hpp"
#include "xtensor/xrandom.hpp"
#include <cmath>
#include <ctime>
#include <vector>

namespace plt = matplotlibcpp;

#define INTERVALS 20

double gbm_next_value(double value, double randomValue) {
    return value+randomValue;
}

int main(int argc, char **argv) { 
    std::vector<double> timePeriods;
    std::vector<double> price;

    xt::random::seed(std::time(nullptr));
    auto Z = xt::random::randn({INTERVALS}, 0.0, 10.0);
    double rando;

    double initialPrice = 200;

    for(int t = 0; t < INTERVALS; t++) {
        rando = Z(t);
        timePeriods.push_back(t);
        initialPrice = gbm_next_value(initialPrice, rando);
        price.push_back(initialPrice);
    }

    plt::plot(timePeriods, price);
    plt::show();

    return 0;
}

