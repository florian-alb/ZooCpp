//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_MEAT_H
#define ZOOREWORK_MEAT_H


#include "Food.h"

class Zoo;

class Meat:public Food{

public:
    Meat(float price);

    virtual void updateFood(int quantity ,Zoo &zoo);

    ~Meat() override;
};


#endif //ZOOREWORK_MEAT_H
