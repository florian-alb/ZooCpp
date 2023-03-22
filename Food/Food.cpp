//
// Created by Florian ALBORA on 19/03/2023.
//

#include "Food.h"

Food::Food(float price) : m_price(price) {};

// getters:
float Food::getPrice() {
    return m_price;
}

Food::~Food() {}
