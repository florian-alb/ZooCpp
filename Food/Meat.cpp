//
// Created by Florian ALBORA on 19/03/2023.
//

#include "Meat.h"
#include "../Zoo/Zoo.h"

Meat::Meat(float price): Food(price){};

void Meat::updateFood(int quantity ,Zoo &zoo){
    zoo.setMeat(quantity);
}

Meat::~Meat() noexcept {}