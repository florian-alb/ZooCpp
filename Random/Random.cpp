//
// Created by Florian ALBORA on 19/03/2023.
//

#include "Random.h"
#include <random>

double Random::getUncertainty(double lowerBound, double upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);
    return dist(gen);
}

bool Random::probability(int probability) {
    srand(time(nullptr));
    int randomNum = rand() % 100 + 1;
    return randomNum <= probability;
}

int Random::randomInt(int i) {
    std::srand(std::time(nullptr));
    return std::rand() % (i + 1);
}

Random::~Random() {}