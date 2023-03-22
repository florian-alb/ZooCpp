//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_EAGLE_H
#define ZOOREWORK_EAGLE_H


#include <iostream>
#include "IAnimal.h"

using namespace std;

class Eagle : public IAnimal {


public:
    Eagle(string name, bool gender);

    int getPrice(int age) override;

    void setBirthDate(int age, int year, int month, int day);

    int getSellPrice(Time date) override;

    int daysBeforeHunger() override;

    void checkHunger(int daysSinceHunger);

    void feed(Zoo &zoo) override;

    void setLastPregnancyDate(const Time *date) override;

    bool canBePregnant(Time *date) override;

    void gestation(Time *date, House &house) override;

    void beSick() override;

    //virtual void removeAnimal();

    ~Eagle() override;

};

#endif //ZOOREWORK_EAGLE_H
