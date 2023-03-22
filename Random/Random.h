//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_RANDOM_H
#define ZOOREWORK_RANDOM_H


class Random {

public:

    double getUncertainty(double lowerBound, double upperBound );
    bool probability(int probability);
    int randomInt(int i);
    ~Random();
};


#endif //ZOOREWORK_RANDOM_H
