//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_FOOD_H
#define ZOOREWORK_FOOD_H


class Zoo;

class Food {
    float m_price;

public :
    Food(float price);

    // getters:
    float getPrice();

    virtual void updateFood(int quantity, Zoo &zoo) = 0;

    virtual ~Food();

};


#endif //ZOOREWORK_FOOD_H
