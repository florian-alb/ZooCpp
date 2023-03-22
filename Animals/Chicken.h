//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_CHICKEN_H
#define ZOOREWORK_CHICKEN_H


#include <iostream>
#include "IAnimal.h"
#include "../Time/Time.h"

using namespace std;

class Chicken : public IAnimal {
    vector<Time *> eggs;

public:
    Chicken(string name, bool gender);

    void setBirthDate(int age, int year, int month, int day);

    int getPrice(int gender) override;

    int getSellPrice(Time date) override;

    int daysBeforeHunger() override;

    void checkHunger(int daysSinceHunger);

    void setLastPregnancyDate(const Time *date) override;

    bool canBePregnant(Time *date) override;

    void gestation(Time *date, House &house) override;

    void feed(Zoo &zoo) override;

    void eggSpawning(Time *date);

    void beSick() override;

    IAnimal* getPartner() override;

    void setPartner(IAnimal *eagle) override;

    string askName(bool gender) override;

    ~Chicken() override;

};


#endif //ZOOREWORK_CHICKEN_H
