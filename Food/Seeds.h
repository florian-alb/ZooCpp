//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_SEEDS_H
#define ZOOREWORK_SEEDS_H


#include "Food.h"

class Zoo;

class Seeds:public Food{

public:
    Seeds(float price);

    virtual void updateFood(int quantity ,Zoo &zoo);

    ~Seeds() override;
};

#endif //ZOOREWORK_SEEDS_H
