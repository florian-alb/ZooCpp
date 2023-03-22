//
// Created by Florian ALBORA on 19/03/2023.
//

#include "Seeds.h"
#include "../Zoo/Zoo.h"

Seeds::Seeds(float price): Food(price){};

void Seeds::updateFood(int quantity ,Zoo &zoo){
    zoo.setSeeds(quantity);
}

Seeds::~Seeds() noexcept {}